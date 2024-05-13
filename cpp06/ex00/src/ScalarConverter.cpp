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

int	checkLimits(const std::string &s, e_type type)
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

e_type	determineIntFloatDouble(const std::string &s)
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
			if (s[i] == '.' && ret != DOUBLE)
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

e_type	getInputType(const std::string &s)
{
	if (s.length() == 1 && !std::isdigit(s[0]))
		return (CHAR);
	else if (s == "nan" || s == "nanf")
		return (NAN);
	else if (s == "-inff" || s == "+inff" || s == "-inf" || s == "+inf")
		return (INF);
	else
		return (determineIntFloatDouble(s));
}

void	ScalarConverter::convert(const std::string &s)
{
		std::string types[7] = {"char","int","float","double","nan","inf","invalid"};
		std::cout << types[getInputType(s)] << std::endl;

	e_type type = getInputType(s);
	if (type == INVALID)
	{
		std::cout << "try some valid shit my man" << std::endl;
		return;
	}
}
