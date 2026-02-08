/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:26:40 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/02/08 14:07:05 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define CYAN	"\033[36m"

//DEFAULT CONSTRUCTOR

Cat::Cat()
{
	std::cout << GREEN << "Cat default constructor" << std::endl << RESET;
	type = "Cat";
}

//COPY CONSTRUCTOR

Cat::Cat(const Cat& other)
{
	std::cout << GREEN << "Cat copy constructor" << std::endl << RESET;
	*this = other;
}

//DESTRUCTOR

Cat::~Cat()
{
	std::cout << RED << "Cat destructor" << std::endl << RESET;
}

//COPY ASSIGNMENT OPERATOR

Cat	&Cat::operator =(const Cat &other)
{
	if (this != &other)
		type = other.type;
	return (*this);
}

//PUBLIC MEMBER FUNCTIONS

void	Cat::makeSound(void) const
{
	std::cout << CYAN << "Purrrr" << std::endl << RESET;
}
