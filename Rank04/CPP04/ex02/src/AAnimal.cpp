/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 20:00:29 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/02/09 20:18:39 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"

//DEFAULT CONSTRUCTOR

AAnimal::AAnimal(): type("AAnimal")
{
	std::cout << GREEN << "AAnimal default constructor" << std::endl << RESET;
}

//COPY CONSTRUCTOR

AAnimal::AAnimal(const AAnimal& other)
{
	std::cout << GREEN << "AAnimal copy constructor" << std::endl << RESET;
	*this = other;
}

//DESTRUCTOR

AAnimal::~AAnimal()
{
	std::cout << RED << "AAnimal destructor" << std::endl << RESET;
}

//COPY ASSIGNMENT OPERATOR

AAnimal	&AAnimal::operator =(const AAnimal &other)
{
	if (this != &other)
		type = other.type;
	return (*this);
}

//PUBLIC MEMBER FUNCTIONS

std::string AAnimal::getType(void) const
{
	return (type);
}
