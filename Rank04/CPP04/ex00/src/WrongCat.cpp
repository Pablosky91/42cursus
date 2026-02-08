/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 16:36:13 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/02/08 11:04:29 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define CYAN	"\033[36m"

//DEFAULT CONSTRUCTOR

WrongCat::WrongCat()
{
	std::cout << GREEN << "WrongCat default constructor" << std::endl << RESET;
	type = "WrongCat";
}

//COPY CONSTRUCTOR

WrongCat::WrongCat(const WrongCat& other)
{
	std::cout << GREEN << "WrongCat copy constructor" << std::endl << RESET;
	*this = other;
}

//DESTRUCTOR

WrongCat::~WrongCat()
{
	std::cout << RED << "WrongCat destructor" << std::endl << RESET;
}

//COPY ASSIGNMENT OPERATOR

WrongCat	&WrongCat::operator =(const WrongCat &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

//PUBLIC MEMBER FUNCTIONS

void	WrongCat::makeSound(void) const
{
	std::cout << CYAN << "Rrrrup" << std::endl << RESET;
}
