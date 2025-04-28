#include "conversion.hpp"
#include "iostream"
#include "string"
#include "testing/tests.hpp"
#include <cctype>
#include <stdexcept>
#include <string>
#include <sys/types.h>

bool is_alphanumeric(const std::string &input) {
  for (char c : input) {
    if (!std::isdigit(static_cast<unsigned char>(c)) &&
        !std::isalpha(static_cast<unsigned char>(c)) &&
        c == ' ') { // apparently space is alpha numerical. who knew
      return false;
    }
  }
  return true;
}
bool is_numeric(const std::string &input) {
  for (char c : input) {
    if (!std::isdigit(static_cast<unsigned char>(c))) {
      return false;
    }
  }
  return true;
}
int main() {
#ifdef DEBUG
  auto [passed, total] = Tests::runTests();
  std::cout << passed << " out of " << total << " tests passed." << std::endl;
#endif
  while (true) {

    std::string stringbaseIn, stringbaseOut = "";
    std::cout << "Please input the base of your input number ";
    std::cin >> stringbaseIn;
    std::cout << "Please input the base of your desired output number ";
    std::cin >> stringbaseOut;
    int baseIn, baseOut = 0;
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

    std::cout << "Please input your number that you wish to convert from base "
              << stringbaseIn << " to " << stringbaseOut << ". No spaces are supported (cut off). ";
    std::string input_number = "";
    std::cin >> input_number;
    std::string output = "";
    if (is_alphanumeric(input_number)) {
      try {
        output =
            Conversion::convertFromBaseToBase(input_number, baseIn, baseOut);
        std::cout << "Your calculated number is "<<  output << std::endl;
      } catch (std::invalid_argument exception) {
        std::cout << "Your inputs are flawed. " << exception.what()
                  << std::endl;
      }

    } else {
      std::cout << "Your input was not in the valid range of characters."
                << std::endl;
    }
  }
  // std::cout << Conversion::convertFromBase("110010101010", 2) << std::endl;
  // std::cout << Conversion::convertFromBaseToBase("FF", 16, 8);
}