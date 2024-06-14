#include "Span.hpp"
#include <algorithm>
#include <cmath>
#include <ctime>
#include <iostream>

//--Con/destructors-----------------------------------------------------------//

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int size) : _maxSize(size) {}

Span::Span(const std::vector<int> &vector) : _maxSize(vector.size()), _data(vector) {}

Span::Span(const Span &other) : _maxSize(other._maxSize)
{
	*this = other;
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
		this->_data = other._data;

	return (*this);
}

Span::~Span() {}

//--Member functions----------------------------------------------------------//

void Span::addNumber(const int n)
{
	if (_data.size() >= _maxSize)
		throw SpanFullException();
	
	_data.push_back(n);
}

unsigned int Span::shortestSpan() const
{
	switch (_data.size())
	{
		case 0:
			throw SpanEmptyException();
		case 1:
			throw SpanSingleNumberException();
	}

	std::vector<int> tmp(_data);
	std::sort(tmp.begin(), tmp.end());
	unsigned int shortestSpan = tmp[1] - tmp[0];
	unsigned int currentSpan;
	for (size_t i = 2; i < tmp.size(); i++)
	{
		currentSpan = tmp[i] - tmp[i - 1];
		if (currentSpan < shortestSpan)
			shortestSpan = currentSpan;
	}

	return (shortestSpan);
}

unsigned int Span::longestSpan() const
{
	switch (_data.size())
	{
		case 0:
			throw SpanEmptyException();
		case 1:
			throw SpanSingleNumberException();
	}
	
	std::vector<int> tmp(_data);
	std::sort(tmp.begin(), tmp.end());
	return (static_cast<long>(tmp.back()) - static_cast<long>(tmp.front()));
}

void Span::addManyNumbers(const int N)
{
	std::srand(std::time(nullptr));
	std::vector<int> randVec(N);
	std::generate(randVec.begin(), randVec.end(), std::rand);

	for (int value : randVec)
	{
		try
		{
			this->addNumber(value);
		}
		catch(const SpanFullException &e)
		{
			std::cerr << e.what() << std::endl;
			break;
		}
	}
}

std::vector<int> Span::getData() const
{
	return (_data);
}

unsigned int Span::getMaxSize() const
{
	return (_maxSize);
}

//--Exceptions----------------------------------------------------------------//

const char *Span::SpanFullException::what() const noexcept
{
	return "span: exception: number can't be added, vector is full";
}

const char *Span::SpanEmptyException::what() const noexcept
{
	return "span: exception: span can't be determined, vector is empty";
}

const char *Span::SpanSingleNumberException::what() const noexcept
{
	return "span: exception: span can't be determined, vector contains only one number";
}
