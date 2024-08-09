#pragma once

#include <stack>

class RPN
{
private:
	std::stack< float > _stack;

public:
	RPN() = default;
	RPN(const RPN &other) = default;
	RPN &operator=(const RPN &other) = default;
	~RPN() = default;

	void readInput(const char *input);
	void calculate(const char op);
};
