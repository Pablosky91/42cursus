/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:59:36 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/02/09 19:59:37 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iomanip>
#include <iostream>

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define CYAN	"\033[36m"

//DEFAULT CONSTRUCTOR

Brain::Brain()
{
	std::cout << GREEN << "Brain default constructor" << std::endl << RESET;
	for (int i = 0; i < 100; i++)
		ideas[i] = "";
}

//COPY CONSTRUCTOR

Brain::Brain(const Brain& other)
{
	std::cout << GREEN << "Brain copy constructor" << std::endl << RESET;
	*this = other;
}

//DESTRUCTOR

Brain::~Brain()
{
	std::cout << RED << "Brain destructor" << std::endl << RESET;
}

//COPY ASSIGNMENT OPERATOR

Brain	&Brain::operator =(const Brain &other)
{
	if (this != &other)
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	return (*this);
}

//PUBLIC MEMBER FUNCTIONS

std::string	Brain::getIdea(int n) const
{
	if (n < 0 || n >= 100)
	{
		std::cout << YELLOW << "This brain only fits 100 ideas" << std::endl << RESET;
		return "";
	}
	return (ideas[n]);
}

void	Brain::setIdea(int n, std::string idea)
{
	if (n < 0 || n >= 100)
	{
		std::cout << YELLOW << "This brain only fits 100 ideas" << std::endl << RESET;
		return ;
	}
	ideas[n] = idea;
}

bool	Brain::newIdea(std::string idea)
{
	for (int i = 0; i < 100; i++)
	{
		if (ideas[i] == "")
		{
			ideas[i] = idea;
			return (true);
		}
	}
	std::cout << YELLOW << "This brain only fits 100 ideas" << std::endl << RESET;
	return (false);
}

void	Brain::listIdeas(void) const
{
	bool	empty = true;

	for (int i = 0; i < 100; i++)
	{
		if (ideas[i] != "")
		{
			std::cout << "Idea " << std::setw(2) << i << ": " << ideas[i] << std::endl;
			empty = false;
		}
	}
	if (empty)
		std::cout << YELLOW << "This brain is empty" << std::endl << RESET;
}
