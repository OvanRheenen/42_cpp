#pragma once

#include <iostream>
#include <algorithm>

template <typename T>
auto easyfind(const T &container, const int toFind) -> decltype(container.begin())
{
	auto it = std::find(container.begin(), container.end(), toFind);

	if (it != container.end())
		std::cout	<< "Value '" << toFind 
					<< "' FOUND in container at: " << std::distance(container.begin(), it) 
					<< std::endl;
	else
		throw NotInContainerException();

	return (it);
}

const char *NotInContainerException::what() const noexcept
{
	return ("Value NOT FOUND in container");
}
