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

	PmergeMe obj;
	try
	{
		obj.readInput(argc, argv);
		// obj.printOriginal();
		// obj.printList();
		obj.sortVector();
		obj.printVector();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	
	return (0);
}
