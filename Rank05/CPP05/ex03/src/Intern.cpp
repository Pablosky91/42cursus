/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 21:50:09 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/04/26 22:23:04 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

//DEFAULT CONSTRUCTOR

Intern::Intern()
{
}

//COPY CONSTRUCTOR

Intern::Intern(const Intern& other)
{
	*this = other;
}

//DESTRUCTOR

Intern::~Intern()
{
}

//COPY ASSIGNMENT OPERATOR

Intern	&Intern::operator =(const Intern &other)
{
	if (this != &other)
		;
	return (*this);
}

static AForm*	formPresidentialPardon(std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm*	formRobotomyRequest(std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm*	formShrubberyCreation(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeForm(std::string type, std::string target)
{
	static std::string	levels[3] = 					{"presidential pardon",		"robotomy request",		"shrubbery creation"};
	static AForm	*(*forms[3])(std::string target) =	{&formPresidentialPardon,	formRobotomyRequest,	formShrubberyCreation};

	for (int i = 0; i < 3; i++)
	{
		if (type == levels[i])
		{
			std::cout << "Intern creates " << type << "\n";
			return (forms[i](target));
		}
	}
	std::cerr << "Intern can't create non-existent " << type << "\n";
	return (NULL);
}
