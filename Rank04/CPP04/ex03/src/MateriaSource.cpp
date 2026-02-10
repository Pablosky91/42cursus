/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:05:39 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/02/10 14:06:36 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"

//DEFAULT CONSTRUCTOR

MateriaSource::MateriaSource()
{
	std::cout << GREEN << "MateriaSource default constructor" << std::endl << RESET;
	for (int i = 0; i < MEM_SIZE; i++)
		_memory[i] = NULL;
}

//COPY CONSTRUCTOR

MateriaSource::MateriaSource(const MateriaSource& other)
{
	std::cout << GREEN << "MateriaSource copy constructor" << std::endl << RESET;
	for (int i = 0; i < MEM_SIZE; i++)
		_memory[i] = NULL;
	*this = other;
}

//DESTRUCTOR

MateriaSource::~MateriaSource()
{
	std::cout << RED << "MateriaSource destructor" << std::endl << RESET;
	for (int i = 0; i < MEM_SIZE; i++)
		delete _memory[i];
}

//COPY ASSIGNMENT OPERATOR

MateriaSource	&MateriaSource::operator =(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < MEM_SIZE; i++)
		{
			delete _memory[i];
			if (other._memory[i])
				_memory[i] = other._memory[i]->clone();
		}
	}
	return (*this);
}

//PUBLIC MEMBER FUNCTIONS

void	MateriaSource::learnMateria(AMateria *materia)
{
	if (!materia)
	{
		std::cout << YELLOW << "This MateriaSource's memory is for AMaterias" << std::endl << RESET;
		return ;
	}
	for (int i = 0; i < MEM_SIZE; i++)
	{
		if (_memory[i])
			continue ;
		_memory[i] = materia->clone();
		std::cout << BLUE << "This MateriaSource learned " << materia->getType() << " in their memory slot " << i << std::endl << RESET;
		return ;
	}
	std::cout << YELLOW << "This MateriaSource memory is full" << std::endl << RESET;

}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	AMateria	*clone;

	for (int i = 0; i < MEM_SIZE; i++)
	{
		if (!_memory[i] || _memory[i]->getType() != type)
			continue ;
		clone = _memory[i]->clone();
		std::cout << BLUE << "This MateriaSource has created " << type << std::endl << RESET;
		return (clone);
	}
	std::cout << YELLOW << "This MateriaSource has not learned " << type << std::endl << RESET;
	return (NULL);
}
