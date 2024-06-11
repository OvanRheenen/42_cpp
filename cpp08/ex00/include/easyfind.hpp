#pragma once

#include <exception>
#include <iostream>
#include <algorithm>

template <typename T>
void easyfind(const T &container, const int n);

class NotInContainerException : public std::exception
{
public:
	virtual const char *what() const noexcept;
};

#include "easyfind.tpp"