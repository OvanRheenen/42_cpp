#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cctype>
#include <cmath>

//--Con/destructors-----------------------------------------------------------//

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

//--Member functions----------------------------------------------------------//

static int	checkLimits(const std::string &s, e_type type)
{
	try
	{
		switch (type)
		{
			case INT:
				std::stoi(s);
				break;
			case DOUBLE:
				std::stod(s);
				break;
			case FLOAT:
				std::cout << "performing stof" << std::endl;
				std::stof(s);
				break;
			default:
				break;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr	<< e.what() 
					<< " couldn't be performed; converted value out of range."
					<< std::endl;
		return (1);
	}
	return (0);
}

static e_type	determineIntFloatDouble(const std::string &s)
{
	size_t len = s.length();
	size_t i = 0;
	e_type ret = INT;

	if (s[0] == '-')
		i++;
	while (i < len)
	{
		if (!std::isdigit(s[i]))
		{
			if (s[i] == '.' && ret != DOUBLE && s[i + 1] && std::isdigit(s[i + 1]))
				ret = DOUBLE;
			else if (s[i] == 'f' && ret == DOUBLE && i == len - 1)
				ret = FLOAT;
			else
			{
				ret = INVALID;
				break;
			}
		}
		i++;
	}
	if (checkLimits(s, ret))
		ret = INVALID;
	return (ret);
}

static e_type	getInputType(const std::string &s)
{
	if (s.length() == 0)
		return (INVALID);
	else if (s.length() == 1 && !std::isdigit(s[0]))
		return (CHAR);
	else if (s == "nan" || s == "nanf")
		return (NOTANUM);
	else if (s == "-inff" || s == "+inff" || s == "-inf" || s == "+inf")
		return (INF);
	else
		return (determineIntFloatDouble(s));
}

static void printConvertChar(const std::string &s)
{
	std::cout	<< "char: '" << s[0] << "'\n"
				<< "int: " << static_cast<int>(s[0]) << "\n"
				<< "float: " << static_cast<float>(s[0]) << ".0f\n"
				<< "double: " << static_cast<double>(s[0]) << ".0"
				<< std::endl;
}

static void printConvertInt(const std::string &s)
{
	int i = std::stoi(s);

	std::cout	<< "char: " << (i > 31 && i < 127 ? ("'" + std::string(1, static_cast<char>(i)) + "'") : "Non displayable") << "\n"
				<< "int: " << i << "\n"
				<< "float: " << static_cast<float>(i) << ".0f\n"
				<< "double: " << static_cast<double>(i) << ".0"
				<< std::endl;
}

static void printConvertFloat(const std::string &s)
{
	float f = std::stof(s);

	std::cout	<< "char: " << (std::floor(f) > 31 && std::floor(f) < 127 ? ("'" + std::string(1, static_cast<char>(f)) + "'") : "Non displayable") << "\n" //should print "impossible" if out of int range
				<< "int: " << (std::floor(f) > (float)INT32_MAX || std::ceil(f) < (float)INT32_MIN ? "impossible" : std::to_string(static_cast<int>(f))) << "\n"
				<< "float: " << std::to_string(f) << (f - std::floor(f) == 0 ? ".0f" : "f") << "\n"
				<< "double: " << static_cast<double>(f) << ((f - std::floor(f) == 0) ? ".0" : "")
				<< std::endl;
}

static void printConvertDouble(const std::string &s)
{
	double d = std::stod(s);

	std::cout	<< "char: " << (std::floor(d) > 31 && std::floor(d) < 127 ? ("'" + std::string(1, static_cast<char>(d)) + "'") : "Non displayable") << "\n" //should print "impossible" if out of int range
				<< "int: " << (std::floor(d) > INT32_MAX || std::ceil(d) < INT32_MIN ? "impossible" : std::to_string(static_cast<int>(d))) << "\n"
				<< "float: " << static_cast<float>(d) << (d - std::floor(d) == 0 ? ".0f" : "f") << "\n"
				<< "double: " << d << (d - std::floor(d) == 0 ? ".0" : "")
				<< std::endl;
}

static void	printNan(void)
{
	std::cout	<< "char: impossible\n"
				<< "int: impossible\n"
				<< "float: nanf\n"
				<< "double: nan"
				<< std::endl;
}

static void	printInf(const std::string &s)
{
	if (s[0] == '-')
	{
		std::cout	<< "char: impossible\n"
					<< "int: impossible\n"
					<< "float: -inff\n"
					<< "double: -inf"
					<< std::endl;
	}
	else
	{
		std::cout	<< "char: impossible\n"
					<< "int: impossible\n"
					<< "float: +inff\n"
					<< "double: +inf"
					<< std::endl;
	}
}

void	ScalarConverter::convert(const std::string &s)
{
		std::string types[7] = {"char","int","float","double","nan","inf","invalid"};
		std::cout << types[getInputType(s)] << std::endl;

	e_type type = getInputType(s);
	if (type == INVALID)
	{
		std::cout << "Input is invalid." << std::endl;
		return;
	}

	switch (type)
	{
		case CHAR:
			printConvertChar(s);
			break;
		case INT:
			printConvertInt(s);
			break;
		case FLOAT:
			printConvertFloat(s);
			break;
		case DOUBLE:
			printConvertDouble(s);
			break;
		case NOTANUM:
			printNan();
			break;
		case INF:
			printInf(s);
			break;
		case INVALID:
			std::cout << "Invalide input." << std::endl;
		default:
			std::cout << "not handled yet" << std::endl;
	}
}
