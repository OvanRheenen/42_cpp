#include "PmergeMe.hpp"
#include "PmergeMe.template.hpp"

//--Con/destructors-----------------------------------------------------------//

// VECTOR /////////////////////////
PmergeMeVector::PmergeMeVector(const int argc, char **argv)
: FordJohnson< std::vector< int >, std::vector< std::pair< int, int > > >(argc, argv) {}

PmergeMeVector::PmergeMeVector() {}

PmergeMeVector::PmergeMeVector(PmergeMeVector &other) 
{
	(void)other;
}

PmergeMeVector &PmergeMeVector::operator=(PmergeMeVector &other)
{
	(void)other;
	return (*this);
}

PmergeMeVector::~PmergeMeVector() {}


// LIST ///////////////////////
PmergeMeList::PmergeMeList(const int argc, char **argv)
: FordJohnson< std::list< int >, std::list< std::pair< int, int > > >(argc, argv) {}

PmergeMeList::PmergeMeList() {}

PmergeMeList::PmergeMeList(PmergeMeList &other) 
{
	(void)other;
}

PmergeMeList &PmergeMeList::operator=(PmergeMeList &other)
{
	(void)other;
	return (*this);
}

PmergeMeList::~PmergeMeList() {}

// DEQUE ////////////////////////
PmergeMeDeque::PmergeMeDeque(const int argc, char **argv)
: FordJohnson< std::deque< int >, std::deque< std::pair< int, int > > >(argc, argv) {}

PmergeMeDeque::PmergeMeDeque() {}

PmergeMeDeque::PmergeMeDeque(PmergeMeDeque &other) 
{
	(void)other;
}

PmergeMeDeque &PmergeMeDeque::operator=(PmergeMeDeque &other)
{
	(void)other;
	return (*this);
}

PmergeMeDeque::~PmergeMeDeque() {}

//--Member functions----------------------------------------------------------//

void PmergeMeVector::printTime() const
{
	std::cout	<< "Time to process a range of " << getSequence().size()
				<< " elements with std::vector : "
				<< std::fixed << std::setprecision(5) << getTime() << " us"
				<< std::endl;
}

void PmergeMeList::printTime() const
{
	std::cout	<< "Time to process a range of " << getSequence().size()
				<< " elements with std::list" << std::right << std::setw(5) << ": "
				<< std::fixed << std::setprecision(5) << getTime() << " us"
				<< std::endl;
}

void PmergeMeDeque::printTime() const
{
	std::cout	<< "Time to process a range of " << getSequence().size()
				<< " elements with std::deque" << std::right << std::setw(4) << ": "
				<< std::fixed << std::setprecision(5) << getTime() << " us"
				<< std::endl;
}
