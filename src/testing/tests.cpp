
#include "tests.hpp"
#include <cstddef>
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
            {"1AF", 16, 2, "110101111"}
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
std::tuple<int, int> sumTuples(const std::vector<std::tuple<int, int>>& data) {
    int sum_a = 0, sum_b = 0;
    for (const auto& [a, b] : data) {
        sum_a += a;
        sum_b += b;
    }
    return {sum_a, sum_b};
}

namespace Tests {
    //Result tuple: {testsPassed,numberOfTestsOverall}
    std::tuple<int,int> runTests() {
    auto results1 = TestsConversionNumericalBaseToBase();
    return sumTuples({results1});      // List of tests to be run, all should pas
    }
}
