#pragma once

#include <vector>
#include <list>

class PmergeMe
{
private:
	std::vector< int > seqOriginal;

	std::vector< int > seqVector;
	std::list< int > seqList;

public:
	PmergeMe();
	PmergeMe(const std::vector< int > &vector, const std::list< int > &list);
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	void readInput(const int argc, char **input);
	void sortVector();

	void printOriginal() const;
	void printVector() const;
	void printList() const;
};
