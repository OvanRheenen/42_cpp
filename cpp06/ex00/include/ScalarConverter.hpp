#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);

public:
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter();

	static void	convert(const std::string &s);
};


#endif