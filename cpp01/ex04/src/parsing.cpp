#include <string.h>
#include <iostream>

int	inputCheck(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout	<< "Please provide 3 arguments" << std::endl
					<< "./replace <filename> <string to replace> <string to replace with>" << std::endl;
		return (1);
	}
	if (strlen(argv[1]) == 0)
	{
		std::cout << "Please provide a valid filename" << std::endl;
		return (1);
	}
	return (0);
}
