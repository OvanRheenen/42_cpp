#pragma once

#include <vector>
#include <exception>

class Span
{
private:
	unsigned int _maxSize;
	std::vector<int> _data;
	Span();

public:
	Span(const unsigned int size);
	Span(const std::vector<int> &vector);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	void addNumber(const int n);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

	void addManyNumbers(const int N);
	
	std::vector<int> getData() const;
	unsigned int getMaxSize() const;

	class SpanFullException : public std::exception
	{
	public:
		virtual const char *what() const noexcept;
	};

	class SpanEmptyException : public std::exception
	{
	public:
		virtual const char *what() const noexcept;
	};

	class SpanSingleNumberException : public std::exception
	{
	public:
		virtual const char *what() const noexcept;
	};
};
