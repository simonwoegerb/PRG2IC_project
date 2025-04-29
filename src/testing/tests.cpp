
#include "tests.hpp"

#include <exception>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

#include "../conversion.hpp"
std::tuple<int, int> TestsConversionNumericalBaseToBase() {
  std::vector<std::tuple<std::string, int, int, std::string>> tests = {
      {"1010", 2, 10, "10"},       {"ff", 16, 10, "255"},
      {"255", 10, 16, "FF"},       {"73", 36, 10, "255"},
      {"255", 10, 36, "73"},       {"0", 2, 36, "0"},
      {"1AF", 16, 2, "110101111"}, {"-1010101", 2, 10, "-85"}}; // all checked with qalc calculator
  int passed = 0;
  for (const auto &[data, from, to, expected] : tests) {
        std::cout << data << " (" << from << "->" << to <<") " << expected;
    try {
      std::string result = Conversion::convertFromBaseToBase(data, from, to);
      if (result == expected) {
        std::cout << " SUCCESS" << std::endl;
        ++passed;
      } else {
        std::cout << " FAILURE (result " << result << ")" << std::endl;
      }
    } catch (const std::exception e) {
      std::cout << "Exception was thrown by test: " << e.what() << std::endl;
    }
  }
  return {passed, tests.size()};
}
namespace Tests {
// Result tuple: {testsPassed,numberOfTestsOverall}
std::tuple<int, int> runTests() {
  auto results1 = TestsConversionNumericalBaseToBase();
  return results1;  }
}  // namespace Tests
