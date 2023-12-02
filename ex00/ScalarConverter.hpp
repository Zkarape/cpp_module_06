#pragma once

#include <iostream>
#include <cstdlib>
#include <climits>

class ScalarConverter
{

    public:
        static void convert(std::string&);
    private:
		static bool isChar(const std::string&);
		static bool isInt(const std::string& arg);
		static bool isDouble(const std::string& arg);
		static bool isFloat(const std::string& arg);
		static bool isPseudoLiteral(const std::string& arg);
        static void printChar(const std::string& arg);
        static void printInt(const std::string& arg);
        static void printDouble(const std::string& arg);
        static void printFloat(const std::string& arg);
    private:
        ~ScalarConverter();
        ScalarConverter&    operator=(const ScalarConverter&);
        ScalarConverter(const std::string&);
        ScalarConverter(const ScalarConverter&);
        ScalarConverter();
};