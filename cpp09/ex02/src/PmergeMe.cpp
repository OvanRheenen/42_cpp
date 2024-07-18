#include "PmergeMe.hpp"
#include <stdexcept>
#include <string>
#include <iostream>

//--Con/destructors-----------------------------------------------------------//

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const std::vector< int > &vector, const std::list< int > &list)
 : seqOriginal(vector), seqVector(vector), seqList(list) {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->seqVector = other.seqVector;
		this->seqList = other.seqList;
	}

	return (*this);
}

PmergeMe::~PmergeMe() {}

//--Member functions----------------------------------------------------------//

static bool isPositiveInteger(std::string &str)
{
	if (str.empty())
		return (false);

	for (char c : str)
	{
		if (!isdigit(c))
			return (false);
	}

	long num = std::stol(str);
	if (num > INT32_MAX)
		return (false);
	
	return (true);
}

void PmergeMe::readInput(const int argc, char **input)
{
	for (int i = 1; i < argc; i++)
	{
		std::string str(input[i]);
		if (!isPositiveInteger(str))
			throw std::invalid_argument("Invalid input: " + str);
		
		int num = std::stoi(str); 
		seqOriginal.push_back(num);
		seqVector.push_back(num);
		seqList.push_back(num);
	}
}

std::vector< std::pair< int, int > > PmergeMe::mergeSortPairs(const std::vector< std::pair< int, int > > &pairs)
{
	if (pairs.size() <= 1)
		return pairs;

	std::vector< std::pair< int, int > > left;
	std::vector< std::pair< int, int > > right;

	size_t middle = pairs.size() / 2;
	
	for (size_t i = 0; i < middle; i++)
		left.push_back(pairs[i]);
	
	for (size_t i = middle; i < pairs.size(); i++)
		right.push_back(pairs[i]);

	left = mergeSortPairs(left);
	right = mergeSortPairs(right);

	return (mergePairs(left, right));
}

std::vector< std::pair< int, int > > PmergeMe::mergePairs(const std::vector< std::pair< int, int > > &left, const std::vector< std::pair< int, int > > &right)
{
	std::vector< std::pair< int, int > > merged;

	size_t leftIndex = 0;
	size_t rightIndex = 0;

	while (leftIndex < left.size() && rightIndex < right.size())
	{
		if (left[leftIndex].first < right[rightIndex].first)
		{
			merged.push_back(left[leftIndex]);
			leftIndex++;
		}
		else
		{
			merged.push_back(right[rightIndex]);
			rightIndex++;
		}
	}

	while (leftIndex < left.size())
	{
		merged.push_back(left[leftIndex]);
		leftIndex++;
	}

	while (rightIndex < right.size())
	{
		merged.push_back(right[rightIndex]);
		rightIndex++;
	}

	return (merged);
}

template <typename Container>
void printContainer(const Container &sequence);

void PmergeMe::sortVector()
{
	// 1. make pairs and sort within pair
	std::vector< std::pair< int, int > > pairs;

	for (size_t i = 1; i < seqOriginal.size(); i += 2)
	{
		if (seqOriginal[i] > seqOriginal[i - 1])
			pairs.push_back(std::make_pair(seqOriginal[i], seqOriginal[i - 1]));
		else
			pairs.push_back(std::make_pair(seqOriginal[i - 1], seqOriginal[i]));
	}

	// 2. recursively merge sort pairs in ascending order (comparing pair.first)
	std::vector< std::pair< int, int > > sortedPairs = mergeSortPairs(pairs);


	seqVector.clear();
	for (const auto& pair : sortedPairs)
	{
		seqVector.push_back(pair.first);
		// seqVector.push_back(pair.second);
	}

	printContainer(seqVector);
}

template <typename Container>
void printContainer(const Container &sequence)
{
	for (int num : sequence)
		std::cout << num << " ";
	std::cout << std::endl;
}

void PmergeMe::printOriginal() const { printContainer(seqOriginal); }

void PmergeMe::printVector() const { printContainer(seqVector); }

void PmergeMe::printList() const { printContainer(seqList); }

//--Other functions-----------------------------------------------------------//
