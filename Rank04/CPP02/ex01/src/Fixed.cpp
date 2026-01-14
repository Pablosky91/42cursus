/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:15:33 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/01/14 20:14:49 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"

//DEFAULT CONSTRUCTOR

Fixed::Fixed(): _value(0)
{
	std::cout << GREEN << "Default constructor called" << std::endl << RESET;
}

//COPY CONSTRUCTOR

Fixed::Fixed(const Fixed& other)
{
	std::cout << GREEN << "Copy constructor called" << std::endl << RESET;
	*this = other;
}

//INT CONSTRUCTOR

Fixed::Fixed(const int value): _value(value << kFractionalBits)
{
	std::cout << GREEN << "Int constructor called" << std::endl << RESET;
}

//FLOAT CONSTRUCTOR

Fixed::Fixed(const float value): _value(roundf(value * (1 << kFractionalBits)))
{
	std::cout << GREEN << "Float constructor called" << std::endl << RESET;
}

//COPY ASSIGNMENT OPERATOR

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << YELLOW << "Copy assignment operator called" << std::endl << RESET;
	if (this != &other)
		_value = other.getRawBits();
	return (*this);
}

//DESTRUCTOR

Fixed::~Fixed()
{
	std::cout << RED << "Destructor called" << std::endl << RESET;
}

//OVERLOAD

std::ostream&	operator<<(std::ostream& ostream, const Fixed& fixed)
{
	ostream << fixed.toFloat();
	return (ostream);
}

//PUBLIC MEMBER FUNCTIONS

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
