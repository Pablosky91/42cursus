/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:27:37 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/02/05 20:17:17 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"

//DEFAULT CONSTRUCTOR

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << GREEN << "Default FragTrap constructor" << std::endl << RESET;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

//COPY CONSTRUCTOR

FragTrap::FragTrap(const FragTrap &other): ClapTrap(other)
{
	std::cout << GREEN << "Copy FragTrap constructor from " << other._name << std::endl << RESET;
	*this = other;
}

//NAME CONSTRUCTOR

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << GREEN << "FragTrap " << name << " constructor" << std::endl << RESET;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

//DESTRUCTOR

FragTrap::~FragTrap()
{
	std::cout << RED << "FragTrap " << _name << " destructor" << std::endl << RESET;
}

//COPY ASSIGNMENT OPERATOR

FragTrap	&FragTrap::operator =(const FragTrap &other)
{
	std::cout << GREEN << "Copy FragTrap assignment from " << other._name << std::endl << RESET;
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return (*this);
}

//PUBLIC MEMBER FUNCTIONS

void	FragTrap::highFivesGuys(void)
{
	if (!hasHitPoints())
		return ;
	std::cout << BLUE << "FragTrap " << _name << " is now high fiving guys" << std::endl << RESET;
}
