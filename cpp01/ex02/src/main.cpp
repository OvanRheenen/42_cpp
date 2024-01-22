#include <iostream>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";

	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "memory address" << std::endl;
	std::cout << "string: " << &str << std::endl;
	std::cout << "pointer: " << &stringPTR << std::endl;
	std::cout << "reference: " << &stringREF << std::endl << std::endl;

	std::cout << "value" << std::endl;
	std::cout << "string: " << str << std::endl;
	std::cout << "pointer: " << stringPTR << std::endl;
	std::cout << "reference: " << stringREF << std::endl;

	return (0);
}
