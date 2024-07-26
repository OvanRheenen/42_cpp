#pragma once

template< class T, class U >
class FordJohnson
{
private:
	T _sequence;
	U _pairs;
	T _originalSequence;
public:
	FordJohnson();
	FordJohnson(const FordJohnson &other);
	FordJohnson &operator=(const FordJohnson &other);
	~FordJohnson();

	void readInput(const int argc, char **input);
	void sortSequence();

	U mergeSortPairs(const U &pairs);
	U mergePairs(const U &left, const U &right);
	void jacobMerge(U sortedPairs);

	void printSequence() const;

	const T &getSequence() const;
	const U &getPairs() const;
};

#include "FordJohnson.template.tpp"