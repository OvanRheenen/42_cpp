#pragma once

#include <exception>
#include <iostream>

template <typename T>
class Array
{
private:
	T* _data;
	unsigned int _size;

public:
	Array();
	Array(const unsigned int n);
	Array(const Array &other);
	const Array &operator=(const Array &other);
	~Array();
	
	template <typename... Args>
	Array(Args... args);

	const T &operator[](const unsigned int index) const;
	T &operator[](const unsigned int index);

	unsigned int size() const;
	T *getData() const;

	void print() const;
};
#include "Array.tpp"