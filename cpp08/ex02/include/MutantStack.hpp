#pragma once

#include <stack>

template < class T, class C > 
class MutantStack : public std::stack< T, C >
{
public:
	MutantStack() {}
	~MutantStack() {}

	MutantStack(const MutantStack &other) { *this = other }
	MutantStack& operator=(const MutantStack& other) {
		if (this != &other)
			std::stack<T, C>::operator=(other);
		return (*this);
	}

	//iterator
};