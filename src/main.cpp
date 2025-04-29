
#include <cctype>
#include <stdexcept>
#include <string>

#include "conversion.hpp"
#include "iostream"
#include "string"
#include "testing/tests.hpp"

bool is_alphanumeric(const std::string &input) {
  for (char c : input) {
    if (!std::isdigit(static_cast<unsigned char>(c)) &&
        !std::isalpha(static_cast<unsigned char>(c)) &&
        !(c == '-')) {  // also allow negative sign
      return false;
    }
  }
  return true;
}
bool is_numeric(const std::string &input) {
  for (char c : input) {
    if (!std::isdigit(static_cast<unsigned char>(
            c))) {  // intentionally not checking for -, as this is only used
                    // for bases and they should not be negative
      return false;
    }
  }
  return true;
}
int main() {
// if the debug macro is set (i.e. by the Makefile), run tests.
#ifdef DEBUG
  auto [passed, total] = Tests::runTests();
  std::cout << passed << " out of " << total << " tests passed." << std::endl;
#endif
  while (true) {
    std::string stringbaseIn, stringbaseOut = "";
    std::cout << "Please input the base of your input number ";
    std::cin >> stringbaseIn;
    if (stringbaseIn == "q" || stringbaseIn=="Q") break;
    std::cout << "Please input the base of your desired output number ";
    std::cin >> stringbaseOut;
    if (stringbaseOut == "q" || stringbaseOut=="Q") break;
    int baseIn, baseOut = 0;
    // check if base inputs are numerical. if not, ask again
    if (is_numeric(stringbaseIn) && is_numeric(stringbaseOut)) {
      baseIn = std::stoi(stringbaseIn);
      baseOut = std::stoi(stringbaseOut);
      if (!(baseIn <= 35 && baseIn >= 2 && baseOut <= 35 && baseOut >= 2)) {
        std::cout << "Your bases are invalid. Try again." << std::endl;
        continue;
      }
    } else {
      std::cout << "Your bases are invalid. Try again." << std::endl;
      continue;
    }
    // spaces not supported because of cin behaviour. getline was considered, but not used.
    std::cout << "Please input your number that you wish to convert from base "
              << stringbaseIn << " to " << stringbaseOut
              << ". No spaces are supported (cut off). ";
    std::string input_string = "";
    std::cin >> input_string;
  
    std::string output = "";
    if (is_alphanumeric(input_string)) {
      try {
        output =
            Conversion::convertFromBaseToBase(input_string, baseIn, baseOut);
        std::cout << input_string << " (" << baseIn << "->" << baseOut <<") " << output << std::endl;
      } catch (std::invalid_argument exception) {
        std::cout << "Your inputs are flawed. " << exception.what()
                  << std::endl;
      }

    } else {
      std::cout << "Your input was not in the valid range of characters."
                << std::endl;
    }
  }
}