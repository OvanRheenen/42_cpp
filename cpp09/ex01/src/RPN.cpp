#include "RPN.hpp"
#include <sstream>	//for std::istringstream
#include <iostream>	//for std::cout

//--Con/destructors-----------------------------------------------------------//

RPN::RPN() {}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN &RPN::operator=(const RPN &other)
{
	(void)other;
	return (*this);
}

RPN::~RPN() {}

//--Member functions----------------------------------------------------------//

static bool isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	return (false);
}

static bool isValidToken(const std::string &token)
{
	if (token.size() != 1)
		return false;
	
	char c = token[0];
	if (
		(c >= '0' && c <= '9') ||
		(c == '+' || c == '-' || c == '*' || c == '/')
	)
		return true;
	
	return false;
}

void RPN::readInput(const char *input)
{
	std::string inputString(input);
	std::istringstream iss(inputString);
	std::string token;

	while (std::getline(iss, token, ' '))
	{
		if (!isValidToken(token))
			throw std::runtime_error("Error: invalid input");

		if(isOperator(token[0]))
			calculate(token[0]);
		else
			_stack.push(std::stoi(token));
	}

	if (_stack.size() != 1)
		throw std::runtime_error("Error: too many operands");
	else
		std::cout << _stack.top() << std::endl;
}

void RPN::calculate(const char op)
{
	if (_stack.size() < 2)
		throw std::runtime_error("Error: not enough operands");

	int a = _stack.top();
	_stack.pop();
	int b = _stack.top();
	_stack.pop();

	switch(op)
	{
		case '+':
			_stack.push(b + a);
			break;
		case '-':
			_stack.push(b - a);
			break;
		case '/':
			if (a == 0)
				throw std::runtime_error("Error: divide by zero");
			_stack.push(b / a);
			break;
		case '*':
			_stack.push(b * a);
			break;
	}
}
