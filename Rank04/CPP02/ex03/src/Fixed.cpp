/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 23:10:59 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/01/18 23:38:51 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>

// DEFAULT CONSTRUCTOR

Fixed::Fixed(): _value(0)
{}

// COPY CONSTRUCTOR

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

// INT CONSTRUCTOR

Fixed::Fixed(const int value): _value(value << kFractionalBits)
{}

// FLOAT CONSTRUCTOR

Fixed::Fixed(const float value): _value(roundf(value * (1 << kFractionalBits)))
{}

// DESTRUCTOR

Fixed::~Fixed()
{}

// COPY ASSIGNMENT OPERATOR

Fixed	&Fixed::operator =(const Fixed &other)
{
	if (this != &other)
		_value = other.getRawBits();
	return (*this);
}

// COMPARISON OPERATORS

bool	Fixed::operator <(const Fixed &other) const
{
	return (_value < other._value);
}

bool	Fixed::operator >(const Fixed &other) const
{
	return (_value > other._value);
}

bool	Fixed::operator <=(const Fixed &other) const
{
	return (_value <= other._value);
}

bool	Fixed::operator >=(const Fixed &other) const
{
	return (_value >= other._value);
}

bool	Fixed::operator ==(const Fixed &other) const
{
	return (_value == other._value);
}

bool	Fixed::operator !=(const Fixed &other) const
{
	return (_value != other._value);
}

// ARITHMETIC OPERATORS

Fixed	Fixed::operator +(const Fixed &other) const
{
	Fixed	result;

	result._value = _value + other._value;
	return (result);
}

Fixed	Fixed::operator -(const Fixed &other) const
{
	Fixed	result;

	result._value = _value - other._value;
	return (result);
}

Fixed	Fixed::operator *(const Fixed &other) const
{
	Fixed	result;

	result._value = static_cast<int>((static_cast<long long>(_value) * other._value) >> kFractionalBits);
	return (result);
}

Fixed	Fixed::operator /(const Fixed &other) const
{
	Fixed	result;

	if (other._value == 0)
		return (0);
	result._value = static_cast<int>((static_cast<long long>(_value) << kFractionalBits) / other._value);
	return (result);
}

// (IN|DE)CREMENT OPERATORS

Fixed	&Fixed::operator ++(void)
{
	_value++;
	return (*this);
}

Fixed	Fixed::operator ++(int)
{
	Fixed old = *this;

	_value++;
	return (old);
}

Fixed	&Fixed::operator --(void)
{
	_value--;
	return (*this);
}

Fixed	Fixed::operator --(int)
{
	Fixed old = *this;
	
	_value--;
	return (old);
}

// OUTPUT OPERATOR

std::ostream	&operator <<(std::ostream &ostream, const Fixed &fixed)
{
	ostream << fixed.toFloat();
	return (ostream);
}

// PUBLIC MEMBER FUNCTIONS

int	Fixed::getRawBits(void) const
{
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	_value = raw;
}

int	Fixed::toInt(void) const
{
	return (_value >> kFractionalBits);
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(_value) / (1 << kFractionalBits));
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}
