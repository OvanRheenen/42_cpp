#pragma once

#include <vector>
#include <deque>
#include <list>
#include "PmergeMe.template.hpp"

// class PmergeMe
// {
// private:
// 	std::vector< int > seqOriginal;

// 	std::vector< int > seqVector;
// 	std::list< int > seqList;

// public:
// 	PmergeMe();
// 	PmergeMe(const std::vector< int > &vector, const std::list< int > &list);
// 	PmergeMe(const PmergeMe &other);
// 	PmergeMe &operator=(const PmergeMe &other);
// 	~PmergeMe();

// 	void readInput(const int argc, char **input);
// 	void sortVector();

// 	std::vector< std::pair< int, int > > mergeSortPairs(const std::vector< std::pair< int, int > > &pairs);
// 	std::vector< std::pair< int, int > > mergePairs(const std::vector< std::pair< int, int > > &left, const std::vector< std::pair< int, int > > &right);
// 	void jacobMerge(std::vector< std::pair< int, int > > sortedPairs);

// 	void printOriginal() const;
// 	void printVector() const;
// 	void printList() const;

// 	const std::vector< int > &getVector() const;
// 	const std::list< int > &getList() const;
// 	const std::vector< int > &getOriginal() const;
// };

class PmergeMeVector : public FordJohnson< std::vector< int >, std::vector< std::pair< int, int > > >
{};

class PmergeMeList  : public FordJohnson< std::vector< int >, std::list< std::pair< int, int > > >
{};

class PmergeMeDeque  : public FordJohnson< std::deque< int >, std::deque< std::pair< int, int > > >
{};
