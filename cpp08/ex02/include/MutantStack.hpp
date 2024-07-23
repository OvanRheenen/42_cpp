#pragma once

#include <stack>

template < typename T, class Container = std::deque< T > >
class MutantStack : public std::stack< T, Container >
{
public:
	MutantStack();
	MutantStack(const MutantStack &other);
	MutantStack& operator=(const MutantStack& other);
	~MutantStack();

	typedef typename Container::iterator				iterator;
	typedef typename Container::reverse_iterator		reverse_iterator;
	typedef typename Container::const_iterator			const_iterator;
	typedef typename Container::const_reverse_iterator	const_reverse_iterator;

	iterator				begin()			{ return (this->c.begin()); };
	iterator				end()			{ return (this->c.end()); };
	// reverse_iterator		rbegin()		{ return (this->c.rbegin()); };
	// reverse_iterator		rend()			{ return (this->c.rend()); };
	const_iterator			cbegin() const	{ return (this->c.cbegin()); };
	const_iterator			cend() const	{ return (this->c.cend()); };
	// const_reverse_iterator	crbegin() const	{ return (this->c.crbegin()); };
	// const_reverse_iterator	crend() const	{ return (this->c.crend()); };
};

#include "MutantStack.tpp"