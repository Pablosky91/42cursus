/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 13:52:59 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/02/08 22:35:37 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define CYAN	"\033[36m"

//DEFAULT CONSTRUCTOR

Dog::Dog()
{
	std::cout << GREEN << "Dog default constructor" << std::endl << RESET;
	type = "Dog";
	brain = new Brain();
}

//COPY CONSTRUCTOR

Dog::Dog(const Dog& other)
{
	std::cout << GREEN << "Dog copy constructor" << std::endl << RESET;
	brain = new Brain;
	*this = other;
}

//DESTRUCTOR

Dog::~Dog()
{
	std::cout << RED << "Dog destructor" << std::endl << RESET;
	delete brain;
}

//COPY ASSIGNMENT OPERATOR

Dog	&Dog::operator =(const Dog &other)
{
	if (this != &other)
	{
		type = other.type;
		*brain = *other.brain;
	}
	return (*this);
}

//PUBLIC MEMBER FUNCTIONS

void	Dog::makeSound(void) const
{
	std::cout << CYAN << "Woof woof!" << std::endl << RESET;
}

Brain	*Dog::getBrain(void) const
{
	return (brain);
}

void	Dog::setBrain(const Brain &brain)
{
	*(this->brain) = brain;
}
