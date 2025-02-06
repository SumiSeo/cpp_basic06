#ifndef SCALARCONVERTER__HPP
#define SCALARCONVERTER__HPP

#include <iostream>

class ScalarConverter
{
    private :
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter &original);
        ScalarConverter &operator=(const ScalarConverter &original);  
        ~ScalarConverter(void);
    public :
        static void convert(std::string &s);


};

#endif