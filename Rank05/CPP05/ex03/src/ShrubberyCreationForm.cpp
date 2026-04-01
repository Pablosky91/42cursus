/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 21:42:47 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/03/31 21:42:48 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

//DEFAULT CONSTRUCTOR

ShrubberyCreationForm::ShrubberyCreationForm():
	AForm("shrubbery creation", 145, 137),
	_target("Untargeted")
{
}

//COPY CONSTRUCTOR

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other):
	AForm(other),
	_target("Untargeted")
{
	*this = other;
}

//TARGET CONSTRUCTOR

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
	AForm("shrubbery creation", 145, 137),
	_target(target)
{
}

//DESTRUCTOR

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

//COPY ASSIGNMENT OPERATOR

ShrubberyCreationForm	&ShrubberyCreationForm::operator =(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator =(other);
		_target = other._target;
	}
	return (*this);
}

//PRIVATE MEMBER FUNCTION

void	ShrubberyCreationForm::executeAction(void) const
{
	std::ofstream	file((_target + "_shrubbery").c_str());

	file << "  / \\   __\n";
	file << " / | \\ /  \\\n";
	file << "/__|__\\    \\\n";
	file << "   |  \\____/\n";
	file << "   |    ||\n";
}
