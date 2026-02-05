/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 22:20:14 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/02/05 20:08:20 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"

//DEFAULT CONSTRUCTOR

ClapTrap::ClapTrap(): _name("Unnamed"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << GREEN << "Default ClapTrap constructor" << std::endl << RESET;
}

//COPY CONSTRUCTOR

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << GREEN << "Copy ClapTrap constructor from " << other._name << std::endl << RESET;
	*this = other;
}

//NAME CONSTRUCTOR

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << GREEN << "ClapTrap " << name << " constructor" << std::endl << RESET;
}

//DESTRUCTOR

ClapTrap::~ClapTrap()
{
	std::cout << RED << "ClapTrap " << _name << " destructor" << std::endl << RESET;
}

//COPY ASSIGNMENT OPERATOR

ClapTrap	&ClapTrap::operator =(const ClapTrap &other)
{
	std::cout << GREEN << "Copy ClapTrap assignment from " << other._name << std::endl << RESET;
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return (*this);
}

//PUBLIC MEMBER FUNCTION

void	ClapTrap::attack(const std::string &target)
{
	if (!hasHitPoints() || !hasEnergyPoints())
		return ;
	std::cout << CYAN << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl << RESET;
	_energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!hasHitPoints())
		return ;
	std::cout << CYAN << "ClapTrap " << _name << " takes " << amount << " damage"<< std::endl << RESET;
	_hitPoints -= amount;
	if (_hitPoints < 0)
		_hitPoints = 0;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!hasHitPoints() || !hasEnergyPoints())
		return ;
	std::cout << CYAN << "ClapTrap " << _name << " regains " << amount << " hit points" << std::endl << RESET;
	_energyPoints--;
	_hitPoints += amount;
}

void	ClapTrap::print(void)
{
	std::cout << MAGENTA << "ClapTrap " << _name << " -> " << _hitPoints << " hit points, " << _energyPoints << " energy points, " << _attackDamage << " attack damage" << std::endl << RESET;
}

//PRIVATE MEMBER FUNCTION

bool	ClapTrap::hasHitPoints(void)
{
	if (_hitPoints <= 0)
	{
		std::cout << YELLOW << "ClapTrap " << _name << " has no hit points left" << std::endl << RESET;
		return (false);
	}
	return (true);
}

bool	ClapTrap::hasEnergyPoints(void)
{
	if (_energyPoints <= 0)
	{
		std::cout << YELLOW << "ClapTrap " << _name << " has no energy points left" << std::endl << RESET;
		return (false);
	}
	return (true);
}
