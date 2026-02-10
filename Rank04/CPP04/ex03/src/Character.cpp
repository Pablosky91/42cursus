/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 10:30:18 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/02/10 13:53:19 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"

//DEFAULT CONSTRUCTOR

Character::Character(): _name("Unnamed")
{
	std::cout << GREEN << "Character default constructor" << std::endl << RESET;
	for (int i = 0; i < INV_SIZE; i++)
		_inventory[i] = NULL;
}

//COPY CONSTRUCTOR

Character::Character(const Character& other)
{
	std::cout << GREEN << "Character copy constructor" << std::endl << RESET;
	for (int i = 0; i < INV_SIZE; i++)
		_inventory[i] = NULL;
	*this = other;
}

//NAME CONSTRUCTOR

Character::Character(std::string name): _name(name)
{
	std::cout << GREEN << "Character name constructor" << std::endl << RESET;
	for (int i = 0; i < INV_SIZE; i++)
		_inventory[i] = NULL;
}

//DESTRUCTOR

Character::~Character()
{
	std::cout << RED << "Character destructor" << std::endl << RESET;
	for (int i = 0; i < INV_SIZE; i++)
		delete _inventory[i];
}

//COPY ASSIGNMENT OPERATOR

Character	&Character::operator =(const Character &other)
{
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < INV_SIZE; i++)
		{
			delete _inventory[i];
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
		}
	}
	return (*this);
}

//PUBLIC MEMBER FUNCTIONS

std::string const &Character::getName(void) const
{
	return (_name);
}

void Character::equip(AMateria *m)
{
	if (!m)
	{
		std::cout << YELLOW << _name << "'s inventory is for AMaterias" << std::endl << RESET;
		return ;
	}
	for (int i = 0; i < INV_SIZE; i++)
	{
		if (_inventory[i])
			continue ;
		_inventory[i] = m;
		std::cout << BLUE << _name << " equipped " << m->getType() << " in their inventory slot " << i << std::endl << RESET;
		return ;
	}
	std::cout << YELLOW << _name << "'s inventory is full" << std::endl << RESET;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= INV_SIZE)
	{
		std::cout << YELLOW << _name << "'s inventory goes from 0 to " << INV_SIZE - 1 << std::endl << RESET;
		return ;
	}
	if (!_inventory[idx])
	{
		std::cout << YELLOW << _name << "'s inventory slot " << idx << " is empty" << std::endl << RESET;
		return ;
	}
	std::cout << BLUE << _name << " unequipped " << _inventory[idx]->getType() << std::endl << RESET;
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= INV_SIZE)
	{
		std::cout << YELLOW << _name << "'s inventory goes from 0 to " << INV_SIZE - 1 << std::endl << RESET;
		return ;
	}
	if (!_inventory[idx])
	{
		std::cout << YELLOW << _name << "'s inventory slot " << idx << " is empty" << std::endl << RESET;
		return ;
	}
	_inventory[idx]->use(target);
}

AMateria	*Character::getSlot(int idx) const
{
	if (idx < 0 || idx >= INV_SIZE)
		std::cout << YELLOW << _name << "'s inventory goes from 0 to " << INV_SIZE - 1 << std::endl << RESET;
	return (_inventory[idx]);
}

void	Character::setName(std::string const name)
{
	_name = name;
}
