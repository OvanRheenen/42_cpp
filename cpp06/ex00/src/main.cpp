#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
		return 0;
	
	ScalarConverter test;
	std::string input(argv[1]);
	
	test.convert(input);
}
