#pragma once

#include <vector>
#include <list>

class PmergeMe
{
private:
	std::vector< int > seqOriginal;

	std::vector< int > seqVector;
	std::list< int > seqList;

	PmergeMe();
public:
	PmergeMe(const std::vector< int > &vector, const std::list< int > &list);
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();
};
