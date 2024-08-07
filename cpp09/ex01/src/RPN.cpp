#include "RPN.hpp"
#include <sstream>		//for std::istringstream
#include <iostream>		//for std::cout
#include <cmath> 		//for std::pow
#include <set>			//for std::set
#include <algorithm>	//for std::find

//--Member functions----------------------------------------------------------//

static bool isOperator(char c)
{
	const std::set< char > operators = {'+', '-', '*', '/', '^'};
	return (operators.find(c) != operators.end());
}

void RPN::readInput(const char *input)
{
	std::string inputString(input);
	std::istringstream iss(inputString);
	std::string token;

	while (std::getline(iss, token, ' '))
	{
		if (!(token.size() == 1 && (std::isdigit(token[0]) || isOperator(token[0]))))
			throw std::invalid_argument("Error: invalid input => " + token);

		if(isOperator(token[0]))
			calculate(token[0]);
		else
			_stack.push(std::stof(token));
	}

	if (_stack.size() != 1)
		throw std::invalid_argument("Error: too many operands");
	else
		std::cout << _stack.top() << std::endl;
}

void RPN::calculate(const char op)
{
	if (_stack.size() < 2)
		throw std::invalid_argument("Error: not enough operands");

	float a = _stack.top();
	_stack.pop();
	float b = _stack.top();
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
		case '^':
			_stack.push(std::pow(b, a));
			break;
	}
}
