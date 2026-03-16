/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:55:41 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/03/16 16:57:56 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include "Form.hpp"
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"

//DEFAULT CONSTRUCTOR

Bureaucrat::Bureaucrat():
	_kName("Unnamed"),
	_grade(75)
{
}

//COPY CONSTRUCTOR

Bureaucrat::Bureaucrat(const Bureaucrat& other):
	_kName(other._kName)
{
	*this = other;
}

//NAME CONSTRUCTOR

Bureaucrat::Bureaucrat(std::string name):
	_kName(name),
	_grade(75)
{
}

//GRADE CONSTRUCTOR

Bureaucrat::Bureaucrat(int grade):
	_kName("Unnamed")
{
	setGrade(grade);
}

//NAME AND GRADE CONSTRUCTOR

Bureaucrat::Bureaucrat(std::string name, int grade):
	_kName(name)
{
	setGrade(grade);
}

//DESTRUCTOR

Bureaucrat::~Bureaucrat()
{
}

//COPY ASSIGNMENT OPERATOR

Bureaucrat	&Bureaucrat::operator =(const Bureaucrat &other)
{
	if (this != &other)
		_grade = other._grade;
	return (*this);
}

// OUTPUT OPERATOR

std::ostream	&operator <<(std::ostream &ostream, const Bureaucrat &bureaucrat)
{
	ostream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".\n";
	return (ostream);
}

//GETTERS

const std::string	Bureaucrat::getName(void) const
{
	return (_kName);
}

int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

//SETTER

void	Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

//PUBLIC MEMBER FUNCTIONS

void	Bureaucrat::increment(void)
{
	setGrade(_grade - 1);
}

void	Bureaucrat::decrement(void)
{
	setGrade(_grade + 1);
}

void	Bureaucrat::signForm(Form &form) const
{
	try
	{
		if (!form.beSigned(*this))
			std::cout << _kName << " couldn't sign " << form.getName() << " because it is already signed.\n";
		else
			std::cout << _kName << " signed " << form.getName() << "\n";
	}
	catch(const std::exception& e)
	{
		std::cout << _kName << " couldn't sign " << form.getName() << " because their grade is too low.\n";
	}
	
}
