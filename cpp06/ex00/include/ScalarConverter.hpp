#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

# include <string>

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

enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	NOTANUM,
	INF,
	INVALID
};

#endif