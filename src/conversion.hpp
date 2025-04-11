#ifndef CONVERSION_H
#define CONVERSION_H
#include <string>
namespace Conversion {
    std::string convertToBase(int number, int targetBase);
    int convertFromBase(std::string data, int base);
    std::string convertFromBaseToBase(std::string data, int dataBase, int targetBase);
    
}

#endif