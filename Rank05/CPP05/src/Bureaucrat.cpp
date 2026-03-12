/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:59:01 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/03/12 21:20:34 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//DEFAULT CONSTRUCTOR

Bureaucrat::Bureaucrat(): _kName("Unnamed"), _grade(75)
{
}

//COPY CONSTRUCTOR

Bureaucrat::Bureaucrat(const Bureaucrat& other): _kName(other._kName)
{
	*this = other;
}

//NAME CONSTRUCTOR

Bureaucrat::Bureaucrat(std::string name): _kName(name), _grade(75)
{
}

//GRADE CONSTRUCTOR

Bureaucrat::Bureaucrat(int grade): _kName("Unnamed")
{
	set_grade(grade);
}

//NAME AND STRING CONSTRUCTOR

Bureaucrat::Bureaucrat(std::string name, int grade): _kName(name)
{
	set_grade(grade);
}

//DESTRUCTOR

Bureaucrat::~Bureaucrat()
{
}

//COPY ASSIGNMENT OPERATOR

Bureaucrat	&Bureaucrat::operator =(const Bureaucrat &other)
{
	if (this != &other)
	{
		_grade = other._grade;
	}
	return (*this);
}

// OUTPUT OPERATOR

std::ostream	&operator <<(std::ostream &ostream, const Bureaucrat &bureaucrat)
{
	ostream << bureaucrat.get_name() << ", bureaucrat grade " << bureaucrat.get_grade() << ".\n";
	return (ostream);
}

//GETTERS

const std::string	Bureaucrat::get_name(void) const
{
	return (_kName);
}

int	Bureaucrat::get_grade(void) const
{
	return (_grade);
}

//SETTER

void	Bureaucrat::set_grade(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

void	Bureaucrat::increment(void)
{
	set_grade(_grade - 1);
}

void	Bureaucrat::decrement(void)
{
	set_grade(_grade + 1);
}

//EXCEPTIONS

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}