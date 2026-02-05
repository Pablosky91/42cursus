/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:26:29 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/02/05 20:08:20 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"

//DEFAULT CONSTRUCTOR

ScavTrap::ScavTrap(): ClapTrap()
{
	std::cout << GREEN << "Default ScavTrap constructor" << std::endl << RESET;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

//COPY CONSTRUCTOR

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other)
{
	std::cout << GREEN << "Copy ScavTrap constructor from " << other._name << std::endl << RESET;
	*this = other;
}

//NAME CONSTRUCTOR

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << GREEN << "ScavTrap " << name << " constructor" << std::endl << RESET;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

//DESTRUCTOR

ScavTrap::~ScavTrap()
{
	std::cout << RED << "ScavTrap " << _name << " destructor" << std::endl << RESET;
}

//COPY ASSIGNMENT OPERATOR

ScavTrap	&ScavTrap::operator =(const ScavTrap &other)
{
	std::cout << GREEN << "Copy ScavTrap assignment from " << other._name << std::endl << RESET;
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

void	ScavTrap::attack(const std::string &target)
{
	if (!hasHitPoints() || !hasEnergyPoints())
		return ;
	std::cout << CYAN << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl << RESET;
	_energyPoints--;
}

void	ScavTrap::guardGate(void)
{
	if (!hasHitPoints())
		return ;
	std::cout << BLUE << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl << RESET;
}
