#include "replace.hpp"

int	main(int argc, char **argv)
{
	if (inputCheck(argc, argv))
		return (1);
	if (openAndCopy(argv[1], argv[2], argv[3]))
		return (1);
	return (0);
}
