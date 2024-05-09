#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

# include <string>

class ScalarConverter
{
private:

public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
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
	NAN,
	INF,
	INVALID
};

#endif