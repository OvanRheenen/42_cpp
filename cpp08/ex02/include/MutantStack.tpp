#pragma once

#include "MutantStack.hpp"

//--Con/destructors-----------------------------------------------------------//
template < typename T >
MutantStack<T>::MutantStack() {};

template < typename T >
MutantStack<T>::~MutantStack() {};

template < typename T >
MutantStack<T>::MutantStack(const MutantStack &other)
{
	*this = other;
}

template < typename T >
MutantStack<T> &MutantStack<T>::operator=(const MutantStack& other)
{
	if (this != &other)
		std::stack<T>::operator=(other);
	return (*this);
}

//--Member functions----------------------------------------------------------//

template < typename T >
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return std::stack<T>::c.begin();
}

template < typename T >
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return std::stack<T>::c.end();
}

template < typename T >
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return std::stack<T>::c.begin();
}

template < typename T >
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return std::stack<T>::c.end();
}

