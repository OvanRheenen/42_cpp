#pragma once

#include <stack>

class RPN
{
private:
	std::stack< int > _stack;

public:
	RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	~RPN();

	void readInput(const char *input);
	void calculate(const char op);
};
