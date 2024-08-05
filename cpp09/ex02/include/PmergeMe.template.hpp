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

	FordJohnson(const FordJohnson &other);
	FordJohnson &operator=(const FordJohnson &other);

public:
	FordJohnson();
	FordJohnson(const int argc, char **argv);
	virtual ~FordJohnson();

	void readInput(const int argc, char **input);

	void MergeInsertionSort();
	void sortSequence();

	U mergeSortPairs(const U &pairs);
	U mergePairs(const U &left, const U &right);
	
	void jacobMerge();
	void insertLoop(typename U::iterator currentPendElem, typename U::iterator prevPendElem);

	void checkSorted() const;
	
	//--Prints-----------------------------------
	void printContainer(const T &sequence) const;
	void printPairs(const U &pairs) const;

	void printOriginal() const;
	void printSequence() const;

	void printBefore() const;
	void printAfter() const;

	virtual void printTime() const = 0;
	
	//--Getters----------------------------------
	const T &getSequence() const;
	const U &getPairs() const;
	double getTime() const;
};

#include "PmergeMe.template.tpp"