#include "Span.hpp"
#include <iostream>
#include <algorithm>

void printSpans(const Span &span)
{
	try
	{
		std::cout	<< "shortest: " << span.shortestSpan()
					<< "\nlongest: " << span.longestSpan()
					<< std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main(void)
{
	{ // subject tests
		std::cout 	<< "---------------------------\n"
					<< "Subject tests:\n" << std::endl;
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{// my tests
		std::cout	<< "---------------------------\n"
					<< "10.000 ints test:\n" << std::endl;
		Span sp = Span(10000);

		sp.addManyNumbers(sp.getMaxSize());
		std::vector<int> test(sp.getData());
		std::cout << "Max: " << *std::max_element(test.begin(), test.end()) << std::endl;
		std::cout << "Min: " << *std::min_element(test.begin(), test.end()) << std::endl;
		std::cout << "Max - Min = " << (*std::max_element(test.begin(), test.end())) - (*std::min_element(test.begin(), test.end())) << std::endl;
		printSpans(sp);
	}
	{
		std::cout 	<< "----------------------------\n"
					<< "min max int test:\n" << std::endl;
		Span sp = Span(2);

		sp.addNumber(INT32_MAX);
		sp.addNumber(INT32_MIN);
		printSpans(sp);
	}
	{
		std::cout 	<< "----------------------------\n"
					<< "identical nums test:\n" << std::endl;
		Span sp = Span(2);

		sp.addNumber(0);
		sp.addNumber(0);
		printSpans(sp);
	}

}
