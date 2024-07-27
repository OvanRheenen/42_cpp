#include "PmergeMe.template.hpp"
#include "PmergeMe.utils.hpp"

#include <stdexcept>
#include <iostream>
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
	// start clock
	this->sortSequence();
	// print
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

	// printPairs(_pairs);
	// 2. recursively merge sort pairs in ascending order (comparing pair.first)
	// mergeSortPairs2(_pairs.begin(), _pairs.end());
	U sortedPairs = mergeSortPairs(_pairs);
	
	// 3. insert element that was paired to smallest element of sorted pairs
	_sequence.insert(_sequence.begin(), sortedPairs.begin()->second);
	// printSequence();
	// 4. insert rest of second elements in sortedPairs, always making at most 3 comparisons
	jacobMerge(sortedPairs);
	// for uneven amount of input, last item is added last to full sorted vector
	if (_originalSequence.size() % 2 == 1)
	{
		auto insertionPoint = std::upper_bound(_sequence.begin(), _sequence.end(), _originalSequence.back());
		
		// std::cout << "to insert: " << _originalSequence.back() << std::endl;
		// std::cout << "insert point: " << *insertionPoint << "\nin list: ";
		// printSequence();

		_sequence.insert(insertionPoint, _originalSequence.back());
	}
}

template< class T, class U >
U FordJohnson< T, U >::mergeSortPairs(const U &pairs)
{
	if (pairs.size() <= 1)
		return (pairs);

	// auto middle = pairs.begin() + pairs.size() / 2;
	auto middle = std::next(pairs.begin(), pairs.size() / 2);
	
	U left(pairs.begin(), middle);
	U right(middle, pairs.end());

	// std::cout << "left: " << left.begin()->first << std::endl;
	// std::cout << "right: " << right.begin()->first << std::endl;

	left = mergeSortPairs(left);
	right = mergeSortPairs(right);

	return (mergePairs(left, right));
}

template< class T, class U >
void FordJohnson< T, U >::mergeSortPairs2(typename U::iterator begin, typename U::iterator end)
{
	if (std::distance(begin, end) > 1)
	{
		auto middle = begin + (std::distance(begin, end) / 2);
		mergeSortPairs2(begin, middle);
		mergeSortPairs2(middle, end);
		mergePairs2(begin, middle, end);
	}
}

template< class T, class U >
void FordJohnson< T, U >::mergePairs2(typename U::iterator begin, typename U::iterator middle, typename U::iterator end)
{
	U left(begin, middle);
	U right(middle, end);

	_sequence.clear();

	auto leftIt = left.begin();
	auto rightIt = right.begin();
	// auto sortedPairsIt = _pairs.begin();
	// auto sortedSeqIt = _sequence.begin();

	while (leftIt != left.end() && rightIt != right.end())
	{
		if (leftIt->first < rightIt->first)
		{
			// *sortedPairsIt++ = *leftIt;
			_pairs.push_back(*leftIt);
			// *sortedSeqIt++ = (*leftIt).first;
			_sequence.push_back(leftIt->first);
			leftIt++;
		}
		else
		{
			// *sortedPairsIt++ = *rightIt;
			_pairs.push_back(*leftIt);
			// *sortedSeqIt++ = (*rightIt).first;
			_sequence.push_back(leftIt->first);
			rightIt++;
		}
	}

	while (leftIt != left.end())
	{
		// *sortedPairsIt++ = *leftIt;
		_pairs.push_back(*leftIt);
		// *sortedSeqIt++ = (*leftIt).first;
		_sequence.push_back(leftIt->first);
		leftIt++;	
	}

	while (rightIt != right.end())
	{
		// *sortedPairsIt++ = *rightIt;
		_pairs.push_back(*leftIt);
		// *sortedSeqIt++ = (*rightIt).first;
		_sequence.push_back(leftIt->first);
		rightIt++;
	}

	// std::cout << "merged: ";
	// printSequence();
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

	// std::cout << "merged: ";
	// printSequence();
	return (merged);
}

template< class T, class U >
void FordJohnson< T, U >::jacobMerge(U sortedPairs)
{
	auto prevPendElem = std::next(sortedPairs.begin(), jacobsthal(2) - 1);
	for (int k = 3; jacobsthal(k) > sortedPairs.size(); k++)
	{
		auto currentPendElem = std::next(sortedPairs.begin(), jacobsthal(k) - 1);

		while (currentPendElem != prevPendElem)
		{
			auto highValueIt = std::upper_bound(_sequence.begin(), _sequence.end(), currentPendElem->first);
			auto insertionPoint = std::upper_bound(_sequence.begin(), highValueIt, currentPendElem->second);

			_sequence.insert(insertionPoint, currentPendElem->second);

			std::advance(currentPendElem, -1);
		}
		prevPendElem = std::next(sortedPairs.begin(), jacobsthal(k) - 1);
		std::cout << "I'm stuck, aren't I?" << std::endl;
	}

	if (prevPendElem != sortedPairs.end())
	{
		// auto currentPendElem = sortedPairs.end() - 1;
		auto currentPendElem = std::next(sortedPairs.end(), -1);
		while (currentPendElem != prevPendElem)
		{
			auto highValueIt = std::upper_bound(_sequence.begin(), _sequence.end(), currentPendElem->first);
			auto insertionPoint = std::upper_bound(_sequence.begin(), highValueIt, currentPendElem->second);
			
			_sequence.insert(insertionPoint, currentPendElem->second);
			
			std::advance(currentPendElem, -1);
		}
	}
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
			std::cout << "...";
			break;
		}

		std::cout << e << " ";
	}
	std::cout << std::endl;
}

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

template < class T, class U>
void FordJohnson< T, U >::printTime() const
{
	std::cout	<< "Time to process a range of " << _originalSequence.size()
				<< " elements with std::[...] : " << _time
				<< std::endl;
}

template< class T, class U >
void FordJohnson< T, U >::printOriginal() const { printContainer(_originalSequence); }

template< class T, class U >
void FordJohnson< T, U >::printSequence() const { printContainer(_sequence); }

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

