/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 00:00:24 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/02/08 14:07:28 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define CYAN	"\033[36m"

//DEFAULT CONSTRUCTOR

WrongAnimal::WrongAnimal(): type("WrongAnimal")
{
	std::cout << GREEN << "WrongAnimal default constructor" << std::endl << RESET;
}

//COPY CONSTRUCTOR

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << GREEN << "WrongAnimal copy constructor" << std::endl << RESET;
	*this = other;
}

//DESTRUCTOR

WrongAnimal::~WrongAnimal()
{
	std::cout << RED << "WrongAnimal destructor" << std::endl << RESET;
}

//COPY ASSIGNMENT OPERATOR

WrongAnimal	&WrongAnimal::operator =(const WrongAnimal &other)
{
	if (this != &other)
		type = other.type;
	return (*this);
}

//PUBLIC MEMBER FUNCTIONS

std::string WrongAnimal::getType(void) const
{
	return (type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << CYAN << "What does the wrong animal say?" << std::endl << RESET;
}
