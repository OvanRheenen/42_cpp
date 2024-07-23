#pragma once

#include "MutantStack.hpp"

//--Con/destructors-----------------------------------------------------------//

template < typename T, class Container >
MutantStack<T, Container>::MutantStack() {};

template < typename T, class Container >
MutantStack<T, Container>::~MutantStack() {};

template < typename T, class Container >
MutantStack<T, Container>::MutantStack(const MutantStack &other)
{
	*this = other;
}

template < typename T, class Container >
MutantStack<T, Container> &MutantStack<T, Container>::operator=(const MutantStack& other)
{
	if (this != &other)
		std::stack<T>::operator=(other);
	return (*this);
}
