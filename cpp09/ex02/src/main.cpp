#include "PmergeMe.hpp"
#include "PmergeMe.template.hpp"
#include <iostream>
#include <list>
#include <deque>
#include <vector>
#include <algorithm>

int main(int argc, char **argv)
{
	if (argc < 3)
	{
		std::cerr	<< "Error: provide at least two arguments:\n" 
					<< "./PmergeMe \"<int a>\" \"<int b>\" [...]"
					<< std::endl;
		return (1);
	}

	FordJohnson< std::list< int >, std::list< std::pair< int, int > > > list(argc, argv);
	FordJohnson< std::vector< int >, std::vector < std::pair < int, int > > > vector(argc, argv);
	FordJohnson< std::deque< int >, std::deque < std::pair < int, int > > > deque(argc, argv);
	
	try
	{
		// list.readInput(argc, argv);
		list.printBefore();
		list.MergeInsertionSort();
		// vector.MergeInsertionSort();
		// deque.MergeInsertionSort();
		list.printAfter();

		if (std::is_sorted(list.getSequence().begin(), list.getSequence().end()))
			std::cout << "The sequence is sorted." << std::endl;
		else
			std::cout << "The sequence is not sorted." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	
	return (0);
}
