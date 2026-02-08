/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:26:42 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/02/08 11:04:22 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define CYAN	"\033[36m"

//DEFAULT CONSTRUCTOR

Dog::Dog()
{
	std::cout << GREEN << "Dog default constructor" << std::endl << RESET;
	type = "Dog";
}

//COPY CONSTRUCTOR

Dog::Dog(const Dog& other)
{
	std::cout << GREEN << "Dog copy constructor" << std::endl << RESET;
	*this = other;
}

//DESTRUCTOR

Dog::~Dog()
{
	std::cout << RED << "Dog destructor" << std::endl << RESET;
}

//COPY ASSIGNMENT OPERATOR

Dog	&Dog::operator =(const Dog &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

//PUBLIC MEMBER FUNCTIONS

void	Dog::makeSound(void) const
{
	std::cout << CYAN << "Woof woof!" << std::endl << RESET;
}
