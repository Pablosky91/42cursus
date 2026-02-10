/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 10:14:59 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/02/10 14:26:12 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"

//DEFAULT CONSTRUCTOR

AMateria::AMateria()
{
	std::cout << GREEN << "AMateria default constructor" << std::endl << RESET;
}

//COPY CONSTRUCTOR

AMateria::AMateria(const AMateria& other)
{
	std::cout << GREEN << "AMateria copy constructor" << std::endl << RESET;
	*this = other;
}

//TYPE CONSTRUCTOR

AMateria::AMateria(std::string const &type): _type(type)
{
	std::cout << GREEN << "AMateria type constructor" << std::endl << RESET;
}

//DESTRUCTOR

AMateria::~AMateria()
{
	std::cout << RED << "AMateria destructor" << std::endl << RESET;
}

//COPY ASSIGNMENT OPERATOR

AMateria	&AMateria::operator =(const AMateria &other)
{
	if (this != &other)
		_type = other._type;
	return (*this);
}

//PUBLIC MEMBER FUNCTIONS

std::string const &AMateria::getType(void) const
{
	return (_type);
}
