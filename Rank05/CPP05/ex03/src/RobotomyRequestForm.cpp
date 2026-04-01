/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 21:42:57 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/03/31 21:42:58 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

//DEFAULT CONSTRUCTOR

RobotomyRequestForm::RobotomyRequestForm():
	AForm("robotomy request", 72, 45),
	_target("Untargeted")
{
}

//COPY CONSTRUCTOR

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other):
	AForm(other),
	_target("Untargeted")
{
	*this = other;
}

//TARGET CONSTRUCTOR

RobotomyRequestForm::RobotomyRequestForm(std::string target):
	AForm("robotomy request", 72, 45),
	_target(target)
{
}

//DESTRUCTOR

RobotomyRequestForm::~RobotomyRequestForm()
{
}

//COPY ASSIGNMENT OPERATOR

RobotomyRequestForm	&RobotomyRequestForm::operator =(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator =(other);
		_target = other._target;
	}
	return (*this);
}

//PRIVATE MEMBER FUNCTION

void	RobotomyRequestForm::executeAction(void) const
{
	static bool	seeded = false;

	if (!seeded)
	{
		srand(time(NULL));
		seeded = true;
	}
	if (rand() % 2)
		std::cout << "DDRRRR...DDDRRRRR...\n" << _target << " has been robotomized\n";
	else
		std::cout << "Robotomy has failed on " << _target << "\n";
}
