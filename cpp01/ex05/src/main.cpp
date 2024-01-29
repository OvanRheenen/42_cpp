#include "Harl.hpp"

static bool	isValidArg(char *arg)
{
	return ((std::string)arg == "DEBUG" ||
			(std::string)arg == "INFO" ||
			(std::string)arg == "WARNING" ||
			(std::string)arg == "ERROR");
}

static int	inputCheck(int argc, char **argv)
{
	if (argc != 2 || !isValidArg(argv[1]))
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
