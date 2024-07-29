#pragma once

template< class T, class U >
class FordJohnson
{
private:
	T _originalSequence;
	T _sequence;
	U _pairs;
	U _sortedPairs;
	double _time;

public:
	FordJohnson();
	FordJohnson(const int argc, char **argv);
	FordJohnson(const FordJohnson &other);
	FordJohnson &operator=(const FordJohnson &other);
	~FordJohnson();

	void MergeInsertionSort();

	void readInput(const int argc, char **input);
	void sortSequence();

	U mergeSortPairs(const U &pairs);
	U mergePairs(const U &left, const U &right);
	void jacobMerge();
	void insertLoop(typename U::iterator currentPendElem, typename U::iterator prevPendElem);

	//--Prints
	void printContainer(const T &sequence) const;
	void printPairs(const U &pairs) const;

	void printOriginal() const;
	void printSequence() const;

	void printBefore() const;
	void printAfter() const;
	void printTime() const;


	//--Getters
	const T &getSequence() const;
	const U &getPairs() const;
};

#include "PmergeMe.template.tpp"