/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:10:01 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/02/05 19:54:34 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"

//DEFAULT CONSTRUCTOR

DiamondTrap::DiamondTrap(): ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << GREEN << "Default DiamondTrap constructor" << std::endl << RESET;
	_name = ClapTrap::_name;
	ClapTrap::_name = ClapTrap::_name + "_clap_name";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
}

//COPY CONSTRUCTOR

DiamondTrap::DiamondTrap(const DiamondTrap& other): ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	std::cout << GREEN << "Copy DiamondTrap constructor from " << other._name << std::endl << RESET;
	*this = other;
}

//NAME CONSTRUCTOR

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	std::cout << GREEN << "DiamondTrap " << name << " constructor" << std::endl << RESET;
	_name = name;
	ClapTrap::_name = ClapTrap::_name + "_clap_name";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
}

//DESTRUCTOR

DiamondTrap::~DiamondTrap()
{
	std::cout << RED << "DiamondTrap " << _name << " destructor" << std::endl << RESET;
}

//COPY ASSIGNMENT OPERATOR

DiamondTrap	&DiamondTrap::operator =(const DiamondTrap &other)
{
	std::cout << GREEN << "Copy DiamondTrap assignment from " << other._name << std::endl << RESET;
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

void DiamondTrap::whoAmI()
{
	if (!hasHitPoints())
		return ;
	std::cout << BLUE << "My DiamondTrap name is " << _name << std::endl << RESET;
	std::cout << BLUE << "My ClapTrap name is " << ClapTrap::_name << std::endl << RESET;
}
