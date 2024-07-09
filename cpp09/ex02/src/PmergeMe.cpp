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

void PmergeMe::sortVector()
{
	std::vector< std::pair< int, int > > pairs;

	for (size_t i = 1; i < seqOriginal.size(); i + 2)
	{
		if (seqOriginal[i] > seqOriginal[i - 1])
			pairs.push_back(std::make_pair(seqOriginal[i], seqOriginal[i - 1]));
		else
			pairs.push_back(std::make_pair(seqOriginal[i - 1], seqOriginal[i]));
	}

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
