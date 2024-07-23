#include "PmergeMe.hpp"
#include <stdexcept>
#include <string>
#include <iostream>
#include <algorithm>

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
	seqVector.clear();

	size_t leftIndex = 0;
	size_t rightIndex = 0;

	while (leftIndex < left.size() && rightIndex < right.size())
	{
		if (left[leftIndex].first < right[rightIndex].first)
		{
			merged.push_back(left[leftIndex]);
			seqVector.push_back(left[leftIndex].first);
			leftIndex++;
		}
		else
		{
			merged.push_back(right[rightIndex]);
			seqVector.push_back(right[rightIndex].first);
			rightIndex++;
		}
	}

	while (leftIndex < left.size())
	{
		merged.push_back(left[leftIndex]);
		seqVector.push_back(left[leftIndex].first);
		leftIndex++;
	}

	while (rightIndex < right.size())
	{
		merged.push_back(right[rightIndex]);
		seqVector.push_back(right[rightIndex].first);
		rightIndex++;
	}

	std::cout << "merged: ";
	printVector();
	return (merged);
}

unsigned long long jacobsthal(int n)
{
	if (n == 0) return (0);
	if (n == 1) return (1);
	return (jacobsthal(n - 1) + (2 * jacobsthal(n - 2)));
}

void PmergeMe::jacobMerge(std::vector< std::pair< int, int > > sortedPairs)
{
	// jacobsthal sequence starting at 3 because we already inserted first element
	// static uint32_t jacobsthal[] = {
	//    0u, 1u, 1u, 3u, 5u, 11u, 21u, 43u, 85u, 171u, 341u, 683u, 1365u
	// };

	uint32_t currentPendIndex;
	// uint32_t prevPendIndex = jacobsthal[2] - 1;
	uint32_t prevPendIndex = jacobsthal(2) - 1;
	for (int k = 3; ; k++)
	{
		// current is - 1 because we use the indexes (starting at 0 instead of 1)
		// currentPendIndex = jacobsthal[k] - 1;
		currentPendIndex = jacobsthal(k) - 1;
		// check if currentPendIndex is not out of range
		if (currentPendIndex + 1 > sortedPairs.size()) break;

		while (currentPendIndex != prevPendIndex)
		{
			//insert sortedPairs[currentPendIndex].second into seqVector

			//find iterator of coupled high value
			std::vector<int>::iterator highValueIt = std::upper_bound(seqVector.begin(), seqVector.end(), sortedPairs[currentPendIndex].first);

			std::vector<int>::iterator insertionPoint = std::upper_bound(seqVector.begin(), highValueIt, sortedPairs[currentPendIndex].second); // niet verder kijken dan positie waar gekoppelde hoge value staat
			std::cout << "to inser21 531 t: " << sortedPairs[currentPendIndex].second << std::endl;
			std::cout << "insert point: " << *insertionPoint << "\nin list: ";
			printVector();

			seqVector.insert(insertionPoint, sortedPairs[currentPendIndex].second);
			
			currentPendIndex--;
		}
		// prevPendIndex = jacobsthal[k] - 1;
		prevPendIndex = jacobsthal(k) - 1;
	}

	std::cout << "prevPned: " << prevPendIndex << std::endl;
	if (prevPendIndex + 1 < sortedPairs.size())
	{
		currentPendIndex = sortedPairs.size() - 1;
		while (currentPendIndex != prevPendIndex)
		{
				//insert sortedPairs[currentPendIndex].second into seqVector

				//find iterator of coupled high value
				std::vector<int>::iterator highValueIt= std::upper_bound(seqVector.begin(), seqVector.end(), sortedPairs[currentPendIndex].first);

				std::vector<int>::iterator insertionPoint = std::upper_bound(seqVector.begin(), highValueIt, sortedPairs[currentPendIndex].second);
				std::cout << "to insert: " << sortedPairs[currentPendIndex].second << std::endl;
				std::cout << "insert point: " << *insertionPoint << "\nin list: ";
				printVector();

				seqVector.insert(insertionPoint, sortedPairs[currentPendIndex].second);
				
				currentPendIndex--;
		}
	}

		/**
	 * 1. Loop over jacobsthal sequence
	 * 2. get the next distance and check if it is not bigger than the distance
	 * 		between the current pending iterator and the last one
	 * 3. advance current large value and low value in pair
	 * 4. loop over pending values decreasing from the jacobsthal k it's at till the
	 * 		lowest not yet inserted pending
	 * 5. find the place for pending to insert using std::upper_bound(begin till current 
	 * 		jacobsthal high value) also using compare somehow
	 * 6. insert at found position
	 * 7. advance iterators and continue loop (back to 2.)
	 */

}

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

	// 3. insert element that was paired to smallest element of sorted pairs
	seqVector.insert(seqVector.begin(), sortedPairs[0].second);

	// 4. insert rest of second elements in sortedPairs, always making at most 3 comparisons
	std::cout << "vector: ";
	printVector();
	jacobMerge(sortedPairs);

	// for uneven amount of input, last item is added last to full sorted vector
	if (seqOriginal.size() % 2 == 1)
	{
		std::vector<int>::iterator insertionPoint = std::upper_bound(seqVector.begin(), seqVector.end(), seqOriginal[seqOriginal.size() - 1]);
		
		std::cout << "to insert: " << seqOriginal[seqOriginal.size() - 1] << std::endl;
		std::cout << "insert point: " << *insertionPoint << "\nin list: ";
		printVector();

		seqVector.insert(insertionPoint, seqOriginal[seqOriginal.size() - 1]);
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

