#pragma once

#include <iostream>

template <typename T>
void iter(T *arr, size_t size, void (*func)(T&))
{
	for (size_t i = 0; i < size; i++)
		func(arr[i]);
}

template <typename T>
void print(T &element)
{
	std::cout << element << std::endl;
}

template <typename T>
void increment(T &element)
{
	element++;
}
