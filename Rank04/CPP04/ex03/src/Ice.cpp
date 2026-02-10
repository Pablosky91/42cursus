/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 10:14:56 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/02/10 11:58:47 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define BLUE	"\033[34m"

//DEFAULT CONSTRUCTOR

Ice::Ice(): AMateria("ice")
{
	std::cout << GREEN << "Ice default constructor" << std::endl << RESET;
}

//COPY CONSTRUCTOR

Ice::Ice(const Ice& other)
{
	std::cout << GREEN << "Ice copy constructor" << std::endl << RESET;
	*this = other;
}

//DESTRUCTOR

Ice::~Ice()
{
	std::cout << RED << "Ice destructor" << std::endl << RESET;
}

//COPY ASSIGNMENT OPERATOR

Ice	&Ice::operator =(const Ice &other)
{
	if (this != &other)
		_type = other._type;
	return (*this);
}

//PUBLIC MEMBER FUNCTIONS

Ice	*Ice::clone(void) const
{
	return (new Ice);
}

void	Ice::use(ICharacter &target)
{
	std::cout << BLUE << "* shoots an ice bolt at " << target.getName() << " *" << std::endl << RESET;
}
