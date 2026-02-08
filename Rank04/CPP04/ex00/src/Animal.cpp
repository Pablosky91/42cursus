/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 22:28:51 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/02/08 11:05:20 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define CYAN	"\033[36m"

//DEFAULT CONSTRUCTOR

Animal::Animal(): type("Animal")
{
	std::cout << GREEN << "Animal default constructor" << std::endl << RESET;
}

//COPY CONSTRUCTOR

Animal::Animal(const Animal& other)
{
	std::cout << GREEN << "Animal copy constructor" << std::endl << RESET;
	*this = other;
}

//DESTRUCTOR

Animal::~Animal()
{
	std::cout << RED << "Animal destructor" << std::endl << RESET;
}

//COPY ASSIGNMENT OPERATOR

Animal	&Animal::operator =(const Animal &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

//PUBLIC MEMBER FUNCTIONS

std::string Animal::getType(void) const
{
	return (type);
}

void	Animal::makeSound(void) const
{
	std::cout << CYAN << "What does the animal say?" << std::endl << RESET;
}
