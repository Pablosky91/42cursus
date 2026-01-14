/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 22:08:25 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/01/14 13:20:21 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"

//DEFAULT CONSTRUCTOR

Fixed::Fixed() : _value(0)
{
	std::cout << GREEN << "Default constructor called" << std::endl << RESET;
}

//COPY CONSTRUCTOR

Fixed::Fixed(const Fixed& other)
{
	std::cout << YELLOW << "Copy constructor called" << std::endl << RESET;
	*this = other;
}

//COPY ASSIGNMENT OPERATOR

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << MAGENTA << "Copy assignment operator called" << std::endl << RESET;
	if (this != &other)
		_value = other.getRawBits();
	return (*this);
}

//DESTRUCTOR

Fixed::~Fixed()
{
	std::cout << RED << "Destructor called" << std::endl << RESET;
}

//PUBLIC MEMBER FUNCTIONS

int Fixed::getRawBits(void) const
{
	std::cout << BLUE << "getRawBits member function called" << std::endl << RESET;
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << CYAN << "setRawBits member function called" << std::endl << RESET;
	_value = raw;
}
