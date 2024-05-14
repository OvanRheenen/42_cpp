#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
		return 0;
	
	std::string input(argv[1]);
	
	ScalarConverter::convert(input);
}
