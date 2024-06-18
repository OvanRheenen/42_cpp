#pragma once

template <typename T>
void easyfind(const T &container, const int toFind)
{
	int index = 0;
	for (auto n : container)
	{
		if (n == toFind)
		{
			std::cout << "Value FOUND in container at index " << index << std::endl;
			return;
		}
		index++;
	}
	throw NotInContainerException();

	// if (std::find(container.begin(), container.end(), toFind) != container.end())
	// 	std::cout	<< "Value FOUND in container" << std::endl;
	// else
	// 	throw NotInContainerException();
}

const char *NotInContainerException::what() const noexcept
{
	return ("Value NOT FOUND in container");
}
