#include "iostream"
#include "testing/tests.hpp"

int main() {
    #ifdef DEBUG 
        auto [passed,total] = Tests::runTests();
        std::cout << passed << " out of " << total << " tests passed." << std::endl;
    #endif
    //std::cout << Conversion::convertFromBase("110010101010", 2) << std::endl;
    //std::cout << Conversion::convertFromBaseToBase("FF", 16, 8);

}