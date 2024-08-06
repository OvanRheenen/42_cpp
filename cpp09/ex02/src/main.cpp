#include "PmergeMe.hpp"
#include "PmergeMe.template.hpp"

#include <iostream>
#include <list>
#include <deque>
#include <vector>

int main(int argc, char **argv)
{
	if (argc < 3)
	{
		std::cerr	<< "Error: provide at least two arguments:\n" 
					<< "./PmergeMe \"<int a>\" \"<int b>\" [...]"
					<< std::endl;
		return (1);
	}

	try
	{
		FordJohnson< std::vector< int >, std::vector< std::pair< int, int > > >	*vector	= new PmergeMeVector(argc, argv);
		FordJohnson< std::list	< int >, std::list	< std::pair< int, int > > >	*list 	= new PmergeMeList(argc, argv);
		FordJohnson< std::deque	< int >, std::deque	< std::pair< int, int > > >	*deque 	= new PmergeMeDeque(argc, argv);
		
		vector->printBefore();

		vector->MergeInsertionSort();
		list->MergeInsertionSort();
		deque->MergeInsertionSort();
		
		vector->printAfter();

		vector->printTime();
		list->printTime();
		deque->printTime();

		vector->checkSorted();
		list->checkSorted();
		deque->checkSorted();
		
		delete vector;
		delete list;
		delete deque;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}

	return (0);
}
