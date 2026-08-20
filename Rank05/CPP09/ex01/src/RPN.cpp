/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 10:32:45 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/08/20 17:08:50 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>
#include <limits>

//DEFAULT CONSTRUCTOR

RPN::RPN()
{
}

//COPY CONSTRUCTOR

RPN::RPN(const RPN& other)
{
	*this = other;
}

//DESTRUCTOR

RPN::~RPN()
{
}

//COPY ASSIGNMENT OPERATOR

RPN	&RPN::operator =(const RPN &other)
{
	if (this != &other)
		_stack = other._stack;
	return (*this);
}

//PUBLIC MEMBER FUNCTIONS

void	RPN::new_token(std::string token)
{
	std::istringstream	iss(token);
	int					value;

	if (token == "+" || token == "-" || token == "*" || token == "/")
		operate(token);
	else
	{
		if (!(iss >> value) || !iss.eof())
			throw std::runtime_error("Unexpected token");
		_stack.push(value);
	}
}

int	RPN::get_result(void)
{
	if (_stack.size() != 1)
		throw std::runtime_error("Not enough operators for calculation");
	return (_stack.top());
}

//PRIVATE MEMBER FUNCTIONS

void	RPN::operate(std::string token)
{
	long	op1, op2;

	if (_stack.size() < 2)
		throw std::runtime_error("Not enough operands for calculation");

	op2 = _stack.top();
	_stack.pop();
	op1 = _stack.top();
	_stack.pop();
	
	if (token == "+")
		_stack.push(op1 + op2);
	else if (token == "-")
		_stack.push(op1 - op2);
	else if (token == "*")
		_stack.push(op1 * op2);
	else if (token == "/" && op2 == 0)
		throw std::runtime_error("Cannot divide by 0");
	else if (token == "/")
		_stack.push(op1 / op2);

	if (_stack.top() > std::numeric_limits<int>::max() || _stack.top() < std::numeric_limits<int>::min())
		throw std::runtime_error("Calculation caused an overflow");
}
