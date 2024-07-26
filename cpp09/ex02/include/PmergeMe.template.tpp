#include "FordJohnson.template.hpp"
#include "PmergeMe.utils.hpp"

//--Con/destructors-----------------------------------------------------------//

template< class T, class U >
FordJohnson< T, U >::FordJohnson() {}

template< class T, class U >
FordJohnson< T, U >::FordJohnson(const FordJohnson &other)
{
	*this = other;
}

template< class T, class U >
FordJohnson< T, U > &FordJohnson< T, U >::operator=(const FordJohnson &other)
{
	if (this != &other)
	{
		this->_sequence = other._sequence;
		this->_pairs = other._pairs;
	}

	return (*this);
}

template< class T, class U >
FordJohnson< T, U >::~FordJohnson() {}

//--Member functions----------------------------------------------------------//

template< class T, class U >
void FordJohnson< T, U >::readInput(const int argc, char **input)
{
	for (int i = 1; i < argc; i++)
	{
		std::string str(input[i]);
		if (!isPositiveInteger(str))
			throw std::invalid_argument("Invalid input: " + str);
		
		int num = std::stoi(str); 
		_originalSequence.push_back(num);
	}
}

template< class T, class U >
void FordJohnson< T, U >::sortSequence()
{
	// 1. make sequence of pairs and sort within pair
	for (auto it std::next(seqOriginal.begin()); it != seqOriginal.end(); ++it)
	{
		if (*it > *std::prev(it))
			_pairs.push_back(std::make_pair(*it, *std::prev(it)));
		else
			_pairs.push_back(std::make_pair(*std::prev(it), *it));
	}

	// 2. recursively merge sort pairs in ascending order (comparing pair.first)

	// 3. insert element that was paired to smallest element of sorted pairs

	// 4. insert rest of second elements in sortedPairs, always making at most 3 comparisons

	// for uneven amount of input, last item is added last to full sorted vector
}

template< class T, class U >
U FordJohnson< T, U >::mergeSortPairs(const U &pairs)
{
}

template< class T, class U >
U FordJohnson< T, U >::mergePairs(const U &left, const U &right)
{
}

template< class T, class U >
void FordJohnson< T, U >::jacobMerge(U sortedPairs)
{
}

template< class T, class U >
void FordJohnson< T, U >::printSequence() const
{
}

//--Getters-------------------------------------------------------------------//

template< class T, class U >
const T &FordJohnson< T, U >::getSequence() const
{
}

template< class T, class U >
const U &FordJohnson< T, U >::getPairs() const
{
}

