
#include "ScalarConverter.hpp"
#include <typeinfo>
#include <cxxabi.h>

int main(int argc, char **argv)
{
    if(argc != 2)
        std::cout << "There is no argument. Please put it one." << std::endl;
    else 
    {
        std::string input = argv[1];        
        ScalarConverter::convert(input);
        // convert it from string to its actual type

        // convert it explicitly to the three other data types
    }
}