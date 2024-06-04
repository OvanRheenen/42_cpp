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
	template <typename... Args> Array(Args... args);
	const Array &operator=(const Array &other);
	~Array();

	const T &operator[](const unsigned int index) const;
	T &operator[](const unsigned int index);

	unsigned int size() const;
	T *getData() const;

	void print() const;

	class OutOfBoundsException : public std::exception
	{
	public:
		virtual const char *what() const noexcept;
	};

};
#include "Array.tpp"