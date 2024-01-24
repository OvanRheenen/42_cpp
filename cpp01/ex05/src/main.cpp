#include "Harl.hpp"
#include <vector>

static int	inputCheck(int argc, char **argv)
{
	std::vector<std::string> args(argv, argv + argc);
	if (argc != 2 || (args[1] != "DEBUG" && args[1] != "INFO" && args[1] != "WARNING" && args[1] != "ERROR"))
	{
		std::cout 	<< "Please run in one of the following ways:" << std::endl
					<< "./harl DEBUG" << std::endl
					<< "./harl INFO" << std::endl
					<< "./harl WARNING" << std::endl
					<< "./harl ERROR" << std::endl;
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (inputCheck(argc, argv))
		return (1);
	Harl	harl;

	harl.complain(argv[1]);
}
