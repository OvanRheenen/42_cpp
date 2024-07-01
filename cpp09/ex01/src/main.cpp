#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr	<< "Error: provide one argument:\n"
					<< "./RPN \"<inverted Polish expression>\""
					<< std::endl;
		return (1);
	}
	else if (std::string(argv[1]).empty())
	{
		std::cerr << "Error: empty string provided as argument" << std::endl;
		return 1;
	}

	RPN obj;
	try
	{
		obj.readInput(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}

	return (0);
}
