/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 21:43:06 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/03/31 21:43:07 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

//DEFAULT CONSTRUCTOR

PresidentialPardonForm::PresidentialPardonForm():
	AForm("presidential pardon", 25, 5),
	_target("Untargeted")
{
}

//COPY CONSTRUCTOR

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other):
	AForm(other),
	_target("Untargeted")
{
	*this = other;
}

//TARGET CONSTRUCTOR

PresidentialPardonForm::PresidentialPardonForm(std::string target):
	AForm("presidential pardon", 25, 5),
	_target(target)
{
}

//DESTRUCTOR

PresidentialPardonForm::~PresidentialPardonForm()
{
}

//COPY ASSIGNMENT OPERATOR

PresidentialPardonForm	&PresidentialPardonForm::operator =(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		AForm::operator =(other);
		_target = other._target;
	}
	return (*this);
}

//PRIVATE MEMBER FUNCTION

void	PresidentialPardonForm::executeAction(void) const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox\n";
}
