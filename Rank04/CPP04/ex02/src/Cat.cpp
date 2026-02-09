/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:59:41 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/02/09 19:59:42 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define CYAN	"\033[36m"

//DEFAULT CONSTRUCTOR

Cat::Cat()
{
	std::cout << GREEN << "Cat default constructor" << std::endl << RESET;
	type = "Cat";
	brain = new Brain();
}

//COPY CONSTRUCTOR

Cat::Cat(const Cat& other)
{
	std::cout << GREEN << "Cat copy constructor" << std::endl << RESET;
	brain = new Brain;
	*this = other;
}

//DESTRUCTOR

Cat::~Cat()
{
	std::cout << RED << "Cat destructor" << std::endl << RESET;
	delete brain;
}

//COPY ASSIGNMENT OPERATOR

Cat	&Cat::operator =(const Cat &other)
{
	if (this != &other)
	{
		type = other.type;
		*brain = *other.brain;
	}
	return (*this);
}

//PUBLIC MEMBER FUNCTIONS

void	Cat::makeSound(void) const
{
	std::cout << CYAN << "Purrrr" << std::endl << RESET;
}

Brain	*Cat::getBrain(void) const
{
	return (brain);
}

void	Cat::setBrain(const Brain &brain)
{
	*(this->brain) = brain;
}
