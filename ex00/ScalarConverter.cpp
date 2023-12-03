#include "./ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter& rhs)
{
    (void)rhs;
}

ScalarConverter::~ScalarConverter()
{}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& rhs)
{
    (void)rhs;
	return (*this);
}

bool ScalarConverter::isChar(const std::string& arg)
{
    if (arg.length() == 1 && !std::isdigit(arg[0]))
        return (true);
    return (false);    
}

bool ScalarConverter::isInt(const std::string& arg)
{
    size_t i = 0;
    if (arg[i] == '-' || arg[i] == '+')
        i++;
    for( ; i < arg.length(); i++)
    {
        if (!std::isdigit(arg[i]))
            return (false);
    }
    if (arg[0] == '-' || arg[0] == '+')
        i--;
    if (i > 10)
        return (false);
    if (i == 10 && arg[0] == '-' && arg.compare("-2147483648") > 0)
        return (false);
    if (i == 10 && arg[0] == '+' && arg.compare("+2147483647") > 0)
        return (false);
    if (i == 10 && arg.compare("2147483647") > 0)
        return (false);
    return (true);
}

bool    ScalarConverter::isDouble(const std::string& arg)
{
    std::string pseoudoDoubles[4] = {"inf", "-inf", "+inf", "nan"};

    for (size_t j = 0; j < 4; j++)
    {
        if (arg == pseoudoDoubles[j])
            return (true);
    }
    size_t i = 0;
    if (arg[i] == '-' || arg[i] == '+')
        i++;
    if (arg[0] == '.')
        return (false);
    for( ; i < arg.length(); i++)
    {
        if (!std::isdigit(arg[i]) && arg[i] != '.')
            return (false);
    }
    if (arg.find('.') != arg.rfind('.'))
        return (false);
    return (true);
}

bool    ScalarConverter::isFloat(const std::string& arg)
{
    std::string pseoudoFloats[4] = {"inff", "-inff", "+inff", "nanf"};
    for (size_t j = 0; j < 4; j++)
    {
        if (arg == pseoudoFloats[j])
            return (true);
    }

    size_t i = 0;
    if (arg[i] == '-' || arg[i] == '+')
        i++;
    if (arg[0] == '.')
        return (false);
    for( ; i < arg.length(); i++)
    {
        if (!std::isdigit(arg[i]) && arg[i] != '.' && arg[i] != 'f')
            return (false);
    }
    if (arg.find('.') != arg.rfind('.'))
        return (false);
    if (arg.find('f') != arg.rfind('f') && arg[arg.length() - 1] == 'f')
        return (false);
    return (true);
}

void    ScalarConverter::printChar(const std::string& arg)
{
    char symbol = arg[0];
    std::cout << "Char:\t"   << symbol << std::endl;
    std::cout << "Int:\t"    << static_cast<int>(symbol) << std::endl;
    std::cout << "Double:\t" << static_cast<double>(symbol) <<".0"<< std::endl;
    std::cout << "Float:\t"  << static_cast<float>(symbol)  <<".0f"<< std::endl;
}

void    ScalarConverter::printInt(const std::string& arg)
{
    int number = std::atoi(arg.c_str());

    if (number < -128 || number > 127)
        std::cout << "Char:\tImpossible" << std::endl;
    else if (number >= 32 && number < 127)
        std::cout << "Char:\t" << static_cast<char>(number) <<  std::endl;
    else
        std::cout << "Char:\tNot Displayable" << std::endl;
    std::cout << "Int:\t"    << static_cast<int>(number) << std::endl;
    std::cout << "Double:\t" << static_cast<double>(number) <<".0"<< std::endl;
    std::cout << "Float:\t"  << static_cast<float>(number)  <<".0f"<< std::endl;
}

bool ScalarConverter::isPseudoLiteral(const std::string& arg)
{
    if (arg == "inf" || arg == "+inf" || arg == "-inf" || arg == "inff" || arg == "+inff" || arg == "-inff" || arg == "nan" || arg == "nanf")
        return true;
    return false;
}

void    ScalarConverter::printDouble(const std::string& arg)
{
    double number = std::strtod(arg.c_str(), NULL);

    if (isPseudoLiteral(arg) || number < -128 || number > 127)
        std::cout << "Char:\tImpossible" << std::endl;
    else if (number >= 32 && number < 127)
        std::cout << "Char:\t" << static_cast<char>(number) <<  std::endl;
    else
        std::cout << "Char:\tNot Displayable" << std::endl;
    if (isPseudoLiteral(arg) || number > INT_MAX || number < INT_MIN)
        std::cout << "Int:\tImpossible" << std::endl;
    else
        std::cout << "Int:\t"    << static_cast<int>(number) << std::endl;
    std::cout << "Double:\t" << number << std::endl;
    std::cout << "Float:\t"  << static_cast<float>(number)  <<"f"<< std::endl;
}

void    ScalarConverter::printFloat(const std::string& arg)
{
    double number = std::strtod(arg.c_str(), NULL);

    if (isPseudoLiteral(arg) || number < -128 || number > 127)
        std::cout << "Char:\tImpossible" << std::endl;
    else if (number >= 32 && number < 127)
        std::cout << "Char:\t" << static_cast<char>(number) <<  std::endl;
    else
        std::cout << "Char:\tNot Displayable" << std::endl;
    if (isPseudoLiteral(arg) || number > INT_MAX || number < INT_MIN)
        std::cout << "Int:\tImpossible" << std::endl;
    else
        std::cout << "Int:\t" << static_cast<int>(number) << std::endl;
    std::cout << "Double:\t" << static_cast<double>(number) << std::endl;
    std::cout << "Float:\t"  << static_cast<float>(number)  <<"f"<< std::endl;
}

void    ScalarConverter::convert(std::string& arg)
{
    std::string type;

    if (isChar(arg))
	{
		printChar(arg); 
	}
    else if (isInt(arg))
	{
		printInt(arg); 
	}
    else if (isDouble(arg))
	{
		printDouble(arg); 
	}
    else if (isFloat(arg))
	{
		printFloat(arg); 
	}
    else { std::cout << "Undefined type" << std::endl; }
}