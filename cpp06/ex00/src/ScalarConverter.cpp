#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cctype>

//--Con/destructors-----------------------------------------------------------//

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	if (this == &other)
		return (*this);
	return (*this);
}

ScalarConverter::~ScalarConverter()
{

}

//--Member functions----------------------------------------------------------//

e_type	determineIntFloatDouble(const std::string &s)
{
	size_t len = s.length();
	size_t i = 0;
	e_type ret = INT;

	if (s.at(0) == '-')
		i++;
	while (i < len)
	{
		if (!std::isdigit(s.at(i)))
		{
			if (s.at(i) == '.' && ret != DOUBLE)
				ret = DOUBLE;
			else if (s.at(i) == 'f' && ret == DOUBLE && i == len - 1)
				ret = FLOAT;
			else
			{
				ret = INVALID;
				break;
			}
		}
		i++;
	}
	return (ret);
}

e_type	getInputType(const std::string &s)
{
	if (s.length() == 1 && !std::isdigit(s.at(0)))
		return (CHAR);
	else if (s == "nan")
		return (NAN);
	else if (s == "-inff" || s == "+inff" || s == "-inf" || s == "+inf")
		return (INF);
	else
		return (determineIntFloatDouble(s));
}

void convertAndPrintChar(e_type type, const std::string &s)
{
	char toPrint;

	if (type == CHAR)
		toPrint = s.at(0);
	else
	{
		//convert int
		//convert float
		//convert double
		toPrint = 'a';
	}

	std::cout << "char: '" << toPrint << "'" << std::endl;
}

void convertAndPrintInt(e_type type, const std::string &s)
{
	int toPrint;

	if (type == INT)
		toPrint = std::stoi(s);
	else
	{
		//convert char
		//convert float
		//convert double
		toPrint = 0;
	}

	std::cout << "int: " << toPrint << std::endl;
}

void convertAndPrintFloat(e_type type, const std::string &s)
{
	float toPrint;

	if (type == FLOAT)
		toPrint = std::stof(s);
	else
	{
		//convert char
		//convert int
		//convert double
		toPrint = 0.0f;
	}

	if (toPrint - (int)toPrint != 0)
		std::cout << "float: " << toPrint << "f" << std::endl;
	else
		std::cout << "float: " << toPrint << ".0f" << std::endl;
}

void convertAndPrintDouble(e_type type, const std::string &s)
{
	double toPrint;

	if (type == DOUBLE)
		toPrint = std::stod(s);
	else
	{
		//convert char
		//convert int
		//convert float
		toPrint = 0.0;
	}

	if (toPrint - (int)toPrint != 0)
		std::cout << "double: " << toPrint << std::endl;
	else
		std::cout << "double: " << toPrint << ".0" << std::endl;
}


void	ScalarConverter::convert(const std::string &s)
{
		std::string types[7] = {"char","int","float","double","nan","inf","invalid"};
		std::cout << types[getInputType(s)] << std::endl;

	e_type type = getInputType(s);
	convertAndPrintChar(type, s);
	convertAndPrintInt(type, s);
	convertAndPrintFloat(type, s);
	convertAndPrintDouble(type, s);
}
