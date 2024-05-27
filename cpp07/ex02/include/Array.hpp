#pragma once

template <typename T>
class Array
{
private:

public:
	Array();
	Array(const unsigned int n);
	Array(const Array &other);
	const Array &operator=(const Array &other);
	~Array();

	const T operator[](const int i);

	size_t size() const;
};
