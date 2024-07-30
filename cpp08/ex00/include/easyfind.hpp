#pragma once

#include <exception>

template <typename T>
auto easyfind(const T &container, const int n) -> decltype(container.begin());

class NotInContainerException : public std::exception
{
public:
	virtual const char *what() const noexcept;
};

#include "easyfind.tpp"