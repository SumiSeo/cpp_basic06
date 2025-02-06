#include "ScalarConverter.hpp"
#include <sstream>
#include <limits>
#include <iomanip>


static void printSpecialValues(const std::string& value)
{
    if (value == "nan")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    } 
    else if (value == "inf" || value == "-inf" || value == "+inf") 
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << value << "f" << std::endl;
        std::cout << "double: " << value << std::endl;
    }
};

static void printChar(const std::string &s)
{
    try{
        std::stringstream ss(s);
        int val;
        ss >> val;
        if(ss.fail())
        {
            std::cout << "char: impossible" << std::endl;
        }
        else if(val < 32 || val > 126)
        {
            std::cout << "char: Non displayable" << std::endl;
        }
        else
        {
            std::cout << "char: '" << static_cast<char>(val) <<"'" << std::endl;
        }
    }
    catch(...)
    {
        std::cout << "char: impossible" << std::endl;
    }
}

static void printInt(const std::string &s)
{
    try
    {
        std::stringstream ss(s);
        int val;
        ss >> val;
        if(ss.fail())
            std::cout << "int : impossible" << std::endl;
        else
            std::cout << "int: " << val << std::endl; 
    }
    catch(...)
    {
        std::cout << "int: impossible" << std::endl;
    }
}

static void printFloat(const std::string &s)
{
    try
    {
        std::stringstream ss(s);
        float val;
        ss >> val;

        if(ss.fail())
            std::cout << "float: impossible" << std::endl;
        else if (val == std::numeric_limits<float>::infinity() || val == -std::numeric_limits<float>::infinity())
            std::cout << "float: " << s << "f" << std::endl;
        else
        {
            std::cout << std::fixed << std::setprecision(1);
            std::cout << "float: " << val << "f" << std::endl;
        }
    }
    catch(...)
    {
        std::cout << "float: impossible" << std::endl;
    }
};

static void printDouble(const std::string &s)
{
    try 
    {
        std::stringstream ss(s);
        double val;
        ss >> val;

        if(ss.fail())
            std::cout << "double: impossible" << std::endl;
        else if (val == std::numeric_limits<double>::infinity() || val == -std::numeric_limits<double>::infinity()) 
             std::cout << "double: " << s << std::endl;
        else
        { 
            std::cout << std::fixed << std::setprecision(1);
            std::cout << "double: " << val << std::endl;
        }
    }
    catch(...)
    {
        std::cout << "double: impossible" << std::endl;
    }
};


void ScalarConverter::convert(std::string &s)
{
  try
  {
    if(s == "nan" || s == "-nan" || s == "+nan")
    {
        printSpecialValues("nan");
        return;
    }
    else if(s == "inf" || s == "-inf" || s =="+inf")
    {
        printSpecialValues("inf");
        return;
    }

    if(s.length() == 1 && !isdigit(s[0]))
    {
        std::cout << "char:'" << s[0] << "'" << std::endl;
    }
    else
        printChar(s);

    printInt(s);
    printFloat(s);
    printDouble(s);
  }
  catch(const std::exception &e)
  {
        std::cout << "Error: " << e.what() << std::endl;
  }
};

