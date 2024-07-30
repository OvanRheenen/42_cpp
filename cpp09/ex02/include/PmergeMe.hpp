#pragma once

#include <vector>
#include <deque>
#include <list>
#include "PmergeMe.template.hpp"

class PmergeMeVector : public FordJohnson< std::vector< int >, std::vector< std::pair< int, int > > >
{
private:
	PmergeMeVector(PmergeMeVector &other);
	PmergeMeVector &operator=(PmergeMeVector &other);

public:
	PmergeMeVector();
	PmergeMeVector(const int argc, char **argv);
	~PmergeMeVector();

	void printTime() const;
};

class PmergeMeList  : public FordJohnson< std::list< int >, std::list< std::pair< int, int > > >
{
private:
	PmergeMeList(PmergeMeList &other);
	PmergeMeList &operator=(PmergeMeList &other);

public:
	PmergeMeList();
	PmergeMeList(const int argc, char **argv);
	~PmergeMeList();

	void printTime() const;
};

class PmergeMeDeque  : public FordJohnson< std::deque< int >, std::deque< std::pair< int, int > > >
{
private:
	PmergeMeDeque(PmergeMeDeque &other);
	PmergeMeDeque &operator=(PmergeMeDeque &other);

public:
	PmergeMeDeque();
	PmergeMeDeque(const int argc, char **argv);
	~PmergeMeDeque();

	void printTime() const;
};
