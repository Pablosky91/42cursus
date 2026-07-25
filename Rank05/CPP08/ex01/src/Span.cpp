/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 13:15:14 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/07/25 13:27:19 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <stdexcept>

//DEFAULT CONSTRUCTOR

Span::Span(): _N(0)
{
}

//INTEGER CONSTRUCTOR

Span::Span(unsigned int N): _N(N)
{
}

//COPY CONSTRUCTOR

Span::Span(const Span &other)
{
	*this = other;
}

//DESTRUCTOR

Span::~Span()
{
}

//COPY ASSIGNMENT OPERATOR

Span	&Span::operator =(const Span &other)
{
	if (this != &other)
	{
		_N = other._N;
		_numbers = other._numbers;
	}
	return (*this);
}

//PUBLIC MEMBER FUNCTIONS

void	Span::addNumber(int value)
{
	if (_numbers.size() >= _N)
		throw std::exception();
	_numbers.insert(std::lower_bound(_numbers.begin(), _numbers.end(), value), value);
}

unsigned int	Span::shortestSpan()
{
	unsigned int	min;

	if (_numbers.size() <= 1)
		throw std::exception();
	min = longestSpan();
	for (unsigned int i = 0; i < _numbers.size() - 1; i++)
		if (static_cast<unsigned int> (_numbers[i + 1] - _numbers[i]) < min)
			min = _numbers[i + 1] - _numbers[i];
	return min;
}

unsigned int	Span::longestSpan()
{
	if (_numbers.size() <= 1)
		throw std::exception();
	return _numbers.back() - _numbers.front();
}
