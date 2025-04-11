#include "conversion.hpp"
#include <cctype>
#include <stdexcept>
#include "algorithm"
//convert 0-9, a-z to number between 0-36
int charToNumber(char c) {
    if (std::isdigit(c)) { 
    // i.e. character "3" is represented by ASCII code 51 and 0 by 48, as such substracting '0' yields the characters content as an int
        return c - '0';     
    } else if (std::isalpha(c)) { //check if
    //-A, as alphabet is consecutive and substracting A makes it start from 0, +10 because A represents 10, ff.
    //is in alphabet
        return std::toupper(c) - 'A' + 10; //supports upper and lowercase, as the same thing    
    } 
     throw std::invalid_argument("Invalid character.");

}
namespace Conversion {

    std::string convertToBase(int number, int targetBase) {
        if (targetBase < 2 || targetBase > 36) {
            throw std::invalid_argument("Invalid targetBase as input, needs to be between 2 and 36");
        } 
        if (number == 0) {
            return "0";
        }
        std::string result;
        bool isNegative = number < 0;
        int n = isNegative ? -number : number; //make number positive, sign will be considered after division algorithm
        while (n>0) {
            int remainder = n % targetBase;
            if (remainder < 10) {
                result += ('0' + remainder); //reverse of charToNumber conversion
            } else {
                result += ('A' + -10 + remainder); // --||--
            }
            n = n/targetBase;
        }
        if (isNegative) {
            result += '-';
        }
        std::reverse(result.begin(), result.end()); //reverse result according to division algorithm
        return result;

    }
    // Converts from given base to base10
    int convertFromBase(std::string data, int base) {
        if (base < 2 || base > 36) {
            throw std::invalid_argument("Invalid base as input, needs to be between 2 and 36");
        } 
        int result = 0;
        for (char c : data) {
            int digit = charToNumber(c);
            if (digit >= base) {
                throw std::invalid_argument("Digit too big for given base.");
            }
            result = result*base+digit;
        }
        return result;
    }
    // intentionally not abstracting away the exceptions
       std::string convertFromBaseToBase(std::string data, int dataBase, int targetBase) {
        return convertToBase(convertFromBase(data, dataBase), targetBase);
    }

    }
