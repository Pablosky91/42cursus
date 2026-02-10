/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 10:14:55 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/02/10 13:26:30 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define BLUE	"\033[34m"

//DEFAULT CONSTRUCTOR

Cure::Cure(): AMateria("cure")
{
	std::cout << GREEN << "Cure default constructor" << std::endl << RESET;
}

//COPY CONSTRUCTOR

Cure::Cure(const Cure& other)
{
	std::cout << GREEN << "Cure copy constructor" << std::endl << RESET;
	*this = other;
}

//DESTRUCTOR

Cure::~Cure()
{
	std::cout << RED << "Cure destructor" << std::endl << RESET;
}

//COPY ASSIGNMENT OPERATOR

Cure	&Cure::operator =(const Cure &other)
{
	if (this != &other)
		_type = other._type;
	return (*this);
}

//PUBLIC MEMBER FUNCTIONS

Cure	*Cure::clone(void) const
{
	return (new Cure);
}

void	Cure::use(ICharacter &target)
{
	std::cout << BLUE << "* heals " << target.getName() << "'s wounds *" << std::endl << RESET;
}
