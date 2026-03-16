/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:54:24 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/03/16 17:02:08 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

#include "Bureaucrat.hpp"
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"

//DEFAULT CONSTRUCTOR

Form::Form():
	_kName("Unnamed"),
	_is_signed(false),
	_kGrade_sign(150),
	_kGrade_execute(150)
{
}

//COPY CONSTRUCTOR

Form::Form(const Form& other):
	_kName(other._kName),
	_kGrade_sign(other._kGrade_sign),
	_kGrade_execute(other._kGrade_execute)
{
	*this = other;
}

//NAME CONSTRUCTOR

Form::Form(std::string name):
	_kName(name),
	_is_signed(false),
	_kGrade_sign(150),
	_kGrade_execute(150)
{
}

//GRADES CONSTRUCTOR

Form::Form(int grade_sign, int grade_execute):
	_kName("Unnamed"),
	_is_signed(false),
	_kGrade_sign(validateGrade(grade_sign)),
	_kGrade_execute(validateGrade(grade_execute))
{
}

//NAME AND GRADES CONSTRUCTOR

Form::Form(std::string name, int grade_sign, int grade_execute):
	_kName(name),
	_is_signed(false),
	_kGrade_sign(validateGrade(grade_sign)),
	_kGrade_execute(validateGrade(grade_execute))
{
}

//DESTRUCTOR

Form::~Form()
{
}

//COPY ASSIGNMENT OPERATOR

Form	&Form::operator =(const Form &other)
{
	if (this != &other)
	{
		_is_signed = other._is_signed;
	}
	return (*this);
}

// OUTPUT OPERATOR

std::ostream	&operator<<(std::ostream &ostream, const Form &form)
{
	ostream << form.getName() << (form.getSigned() ? " (signed)" : " (unsigned)");
	ostream << ", sign grade " << form.getGradeSign();
	ostream << ", execute grade " << form.getGradeExecute() << ".\n";
	return (ostream);
}

//GETTERS

const std::string	Form::getName(void) const
{
	return (_kName);
}

bool	Form::getSigned(void) const
{
	return (_is_signed);
}

int	Form::getGradeSign(void) const
{
	return (_kGrade_sign);
}

int	Form::getGradeExecute(void) const
{
	return (_kGrade_execute);
}

//SETTER

void	Form::setSigned(bool is_signed)
{
	_is_signed = is_signed;
}

//PUBLIC MEMBER FUNCTIONS

bool	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (_is_signed)
		return (false);
	if (bureaucrat.getGrade() > _kGrade_sign)
		throw GradeTooLowException();
	_is_signed = true;
	return (true);
}

//PRIVATE STATIC FUNCTION

int	Form::validateGrade(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	return (grade);
}
