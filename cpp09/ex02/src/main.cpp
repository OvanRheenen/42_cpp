#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc < 3)
	{
		std::cerr	<< "Error: provide at least two arguments:\n" 
					<< "./PmergeMe \"<int a>\" \"<int b>\" [...]"
					<< std::endl;
		return (1);
	}

	(void)argv;
}
