#include "PmergeMe.template.hpp"
#include "PmergeMe.utils.hpp"

#include <iostream>
#include <iomanip>
#include <algorithm>

//--Con/destructors-----------------------------------------------------------//

template< class T, class U >
FordJohnson< T, U >::FordJohnson() {}

template< class T, class U >
FordJohnson< T, U >::FordJohnson(const int argc, char **argv)
{
	readInput(argc, argv);
}

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
void FordJohnson< T, U >::MergeInsertionSort()
{
	clock_t start = clock();

    sortSequence();

    clock_t end = clock();
    _time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
}

template< class T, class U >
void FordJohnson< T, U >::sortSequence()
{
	// 1. make sequence of pairs and sort within pair
	auto it = std::next(_originalSequence.begin());
	while (it != _originalSequence.end())
	{
		if (*it > *std::prev(it))
			_pairs.push_back(std::make_pair(*it, *std::prev(it)));
		else
			_pairs.push_back(std::make_pair(*std::prev(it), *it));

		if (std::distance(it, _originalSequence.end()) <= 2) break;	
		std::advance(it, 2);
	}

	// 2. recursively merge sort pairs in ascending order (comparing pair.first)
	_sortedPairs = mergeSortPairs(_pairs);

	// 3. insert element that was paired to smallest element of sorted pairs
	_sequence.insert(_sequence.begin(), _sortedPairs.begin()->second);
	
	// 4. insert rest of second elements in _sortedPairs, always making at most 3 comparisons
	jacobMerge();

	// 5. for uneven amount of input, last item is added last to full sorted vector
	if (_originalSequence.size() % 2 == 1)
	{
		auto insertionPoint = std::upper_bound(_sequence.begin(), _sequence.end(), _originalSequence.back());		
		_sequence.insert(insertionPoint, _originalSequence.back());
	}
}

template< class T, class U >
U FordJohnson< T, U >::mergeSortPairs(const U &pairs)
{
	if (pairs.size() <= 1)
	{
		_sequence.push_back(pairs.begin()->first);
		return (pairs);	
	}

	auto middle = std::next(pairs.begin(), pairs.size() / 2);
	
	U left(pairs.begin(), middle);
	U right(middle, pairs.end());

	left = mergeSortPairs(left);
	right = mergeSortPairs(right);

	return (mergePairs(left, right));
}

template< class T, class U >
U FordJohnson< T, U >::mergePairs(const U &left, const U &right)
{
	U merged;
	_sequence.clear();

	auto leftIt = left.begin();
	auto rightIt = right.begin();

	while (leftIt != left.end() && rightIt != right.end())
	{
		if (leftIt->first < rightIt->first)
		{
			merged.push_back(*leftIt);
			_sequence.push_back(leftIt->first);
			leftIt++;
		}
		else
		{
			merged.push_back(*rightIt);
			_sequence.push_back(rightIt->first);
			rightIt++;
		}
	}

	while (leftIt != left.end())
	{
		merged.push_back(*leftIt);
		_sequence.push_back(leftIt->first);
		leftIt++;
	}

	while (rightIt != right.end())
	{
		merged.push_back(*rightIt);
		_sequence.push_back(rightIt->first);
		rightIt++;
	}

	return (merged);
}

template< class T, class U >
void FordJohnson< T, U >::insertLoop(typename U::iterator currentPendElem, typename U::iterator prevPendElem)
{
	while (currentPendElem != prevPendElem)
	{
		auto highValueIt = std::upper_bound(_sequence.begin(), _sequence.end(), currentPendElem->first);
		auto insertionPoint = std::upper_bound(_sequence.begin(), highValueIt, currentPendElem->second);
		
		_sequence.insert(insertionPoint, currentPendElem->second);
		
		std::advance(currentPendElem, -1);
	}
}

template< class T, class U >
void FordJohnson< T, U >::jacobMerge()
{
	auto prevPendElem = std::next(_sortedPairs.begin(), jacobsthal(2) - 1);
	
	// loop over every jacobsthal number lower than the amount of pairs
	for (int k = 3; jacobsthal(k) < _sortedPairs.size(); k++)
	{
		insertLoop(std::next(_sortedPairs.begin(), jacobsthal(k) - 1), prevPendElem);
		prevPendElem = std::next(_sortedPairs.begin(), jacobsthal(k) - 1);
	}

	// insert the rest of the pairs with indexes higher than the last jacobsthal number
	if (prevPendElem != _sortedPairs.end())
		insertLoop(std::next(_sortedPairs.end(), -1), prevPendElem);
}

template< class T, class U >
void FordJohnson< T, U >::checkSorted() const
{
	if (!std::is_sorted(_sequence.begin(), _sequence.end()))
		throw std::runtime_error("The sequence is not sorted");
}

//--Prints--------------------------------------------------------------------//

template< class T, class U >
void FordJohnson< T, U >::printContainer(const T &sequence) const
{
	int counter = 0;
	for (auto e : sequence)
	{
		if (counter++ == 10)
		{
			std::cout << "[...]";
			break;
		}

		std::cout << e << " ";
	}
	std::cout << std::endl;
}

template< class T, class U >
void FordJohnson< T, U >::printOriginal() const { printContainer(_originalSequence); }

template< class T, class U >
void FordJohnson< T, U >::printSequence() const { printContainer(_sequence); }

template< class T, class U >
void FordJohnson< T, U >::printPairs(const U &pairs) const
{
	for (const auto &pair : pairs)
		std::cout << "(" << pair.first << ", " << pair.second << ") ";
	std::cout << std::endl;
}

template< class T, class U >
void FordJohnson< T, U >::printBefore() const
{
	std::cout << "Before: "; printOriginal();
}

template< class T, class U >
void FordJohnson< T, U >::printAfter() const
{
	std::cout << "After:  "; printSequence();
}

//--Getters-------------------------------------------------------------------//

template< class T, class U >
const T &FordJohnson< T, U >::getSequence() const
{
	return (_sequence);
}

template< class T, class U >
const U &FordJohnson< T, U >::getPairs() const
{
	return (_pairs);
}

template< class T, class U >
double FordJohnson< T, U >::getTime() const
{
	return (_time);
}
