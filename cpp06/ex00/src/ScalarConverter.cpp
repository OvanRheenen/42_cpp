#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cctype>
#include <cmath>

//--Con/destructors-----------------------------------------------------------//

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
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
				std::stof(s);
				break;
			default:; //do nothing, shouldn't get to here
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
	char c = s[0];

	std::cout	<< "char: '" << c << "'\n"
				<< "int: " << static_cast<int>(c) << "\n"
				<< "float: " << static_cast<float>(c) << ".0f\n"
				<< "double: " << static_cast<double>(c) << ".0"
				<< std::endl;
}

static void printConvertInt(const std::string &s)
{
	int i = std::stoi(s);

	std::string charConversion;
	if (i > 31 && i < 127)
		charConversion = "'" + std::string(1, static_cast<char>(i)) + "'";
	else
		charConversion = "Non displayable";

	std::string floatSuffix;
	if (i > -1000000 && i < 1000000)
		floatSuffix = ".0f";
	else
		floatSuffix = "f";

	std::string doubleSuffix;
	if (i > -1000000 && i < 1000000)
		doubleSuffix = ".0";
	else
		doubleSuffix = "";

	std::cout	<< "char: " << charConversion << "\n"
				<< "int: " << i << "\n"
				<< "float: " << static_cast<float>(i) << floatSuffix << "\n"
				<< "double: " << static_cast<double>(i) << doubleSuffix
				<< std::endl;
}

static void printConvertFloat(const std::string &s)
{
	float f = std::stof(s);

	std::string charConversion;
	if (std::floor(f) > 31 && std::floor(f) < 127)
		charConversion = "'" + std::string(1, static_cast<char>(f)) + "'";
	else
		charConversion = "Non displayable";

	std::string intConversion;
	if (std::floor(f) <= (float)INT32_MAX && std::ceil(f) >= (float)INT32_MIN)
		intConversion = std::to_string(static_cast<int>(f));
	else
		intConversion = charConversion = "impossible";
	
	std::string floatSuffix;
	std::string doubleSuffix;
	if (f > -1000000 && f < 1000000 && f - std::floor(f) == 0)
		floatSuffix = doubleSuffix = ".0";
	floatSuffix += "f";

	std::cout	<< "char: " << charConversion << "\n"
				<< "int: " << intConversion << "\n"
				<< "float: " << f << floatSuffix << "\n"
				<< "double: " << static_cast<double>(f) << doubleSuffix
				<< std::endl;
}

static void printConvertDouble(const std::string &s)
{
	double d = std::stod(s);

	std::string charConversion;
	if (std::floor(d) > 31 && std::floor(d) < 127)
		charConversion = "'" + std::string(1, static_cast<char>(d)) + "'";
	else
		charConversion = "Non displayable";

	std::string intConversion;
	if (std::floor(d) <= INT32_MAX && std::ceil(d) >= INT32_MIN)
		intConversion = std::to_string(static_cast<int>(d));
	else
		intConversion = charConversion = "impossible";

	std::string floatSuffix;
	std::string doubleSuffix;
	if (d > -1000000 && d < 1000000 && d - std::floor(d) == 0)
		floatSuffix = doubleSuffix = ".0";
	floatSuffix += "f";

	std::cout	<< "char: " << charConversion << "\n"
				<< "int: " << intConversion << "\n"
				<< "float: " << static_cast<float>(d) << floatSuffix << "\n"
				<< "double: " << d << doubleSuffix
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
	e_type type = getInputType(s);

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
			std::cout << "Invalid input." << std::endl;
	}
}
