
#include "tests.hpp"
#include <exception>
#include <string>
#include <vector>
#include <iostream>
#include "../conversion.hpp"
#include <tuple>
std::tuple<int,int> TestsConversionNumericalBaseToBase() {
        std::vector<std::tuple<std::string,int,int,std::string>> tests = {
            {"1010", 2, 10,"10"},
            {"ff",16,10,"255"},
            {"255",10,16,"FF"},
            {"73", 36,10,"255"},
            {"255",10,36,"73"},
            {"0",2,36,"0"},
            {"1AF", 16, 2, "110101111"},
            {"-1010101", 2,10,"-85"}
            };
        int passed = 0;
        for (const auto& [data,from,to,expected]: tests) {
            try {
                std::string result = Conversion::convertFromBaseToBase(data, from, to);
                if (result == expected) {
                    ++passed;
                } else {
                    std:: cout << data << " should be " << expected << " (base " << to << "->" << from << "), but was " << result << std::endl; 
                }
            } catch(const std::exception e)  {
                std::cout << "Exception was thrown: " << e.what() << std::endl;
            }
             
        } 
        return {passed, tests.size()};
        }
// Just a helper function to add up the test results of different test sets/functions

namespace Tests {
    //Result tuple: {testsPassed,numberOfTestsOverall}
    std::tuple<int,int> runTests() {
    auto results1 = TestsConversionNumericalBaseToBase();
    return results1;      // List of tests to be run, all should pas
    }
}
