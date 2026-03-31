/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 19:54:05 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/03/31 19:54:06 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#include "Bureaucrat.hpp"
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"
#include "UnsignedFormException.hpp"

//DEFAULT CONSTRUCTOR

AForm::AForm():
	_kName("Unnamed"),
	_is_signed(false),
	_kGrade_sign(150),
	_kGrade_execute(150)
{
}

//COPY CONSTRUCTOR

AForm::AForm(const AForm& other):
	_kName(other._kName),
	_kGrade_sign(other._kGrade_sign),
	_kGrade_execute(other._kGrade_execute)
{
	*this = other;
}

//NAME CONSTRUCTOR

AForm::AForm(std::string name):
	_kName(name),
	_is_signed(false),
	_kGrade_sign(150),
	_kGrade_execute(150)
{
}

//GRADES CONSTRUCTOR

AForm::AForm(int grade_sign, int grade_execute):
	_kName("Unnamed"),
	_is_signed(false),
	_kGrade_sign(validateGrade(grade_sign)),
	_kGrade_execute(validateGrade(grade_execute))
{
}

//NAME AND GRADES CONSTRUCTOR

AForm::AForm(std::string name, int grade_sign, int grade_execute):
	_kName(name),
	_is_signed(false),
	_kGrade_sign(validateGrade(grade_sign)),
	_kGrade_execute(validateGrade(grade_execute))
{
}

//DESTRUCTOR

AForm::~AForm()
{
}

//COPY ASSIGNMENT OPERATOR

AForm	&AForm::operator =(const AForm &other)
{
	if (this != &other)
	{
		_is_signed = other._is_signed;
	}
	return (*this);
}

// OUTPUT OPERATOR

std::ostream	&operator<<(std::ostream &ostream, const AForm &form)
{
	ostream << form.getName() << (form.getSigned() ? " (signed)" : " (unsigned)");
	ostream << ", sign grade " << form.getGradeSign();
	ostream << ", execute grade " << form.getGradeExecute() << ".\n";
	return (ostream);
}

//GETTERS

const std::string	AForm::getName(void) const
{
	return (_kName);
}

bool	AForm::getSigned(void) const
{
	return (_is_signed);
}

int	AForm::getGradeSign(void) const
{
	return (_kGrade_sign);
}

int	AForm::getGradeExecute(void) const
{
	return (_kGrade_execute);
}

//SETTER

void	AForm::setSigned(bool is_signed)
{
	_is_signed = is_signed;
}

//PUBLIC MEMBER FUNCTIONS

bool	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (_is_signed)
		return (false);
	if (bureaucrat.getGrade() > _kGrade_sign)
		throw GradeTooLowException();
	_is_signed = true;
	return (true);
}

void	AForm::execute(const Bureaucrat &executor) const
{
	if (!_is_signed)
		throw UnsignedFormException();
	if (executor.getGrade() > _kGrade_execute)
		throw GradeTooLowException();
	executeAction();
}

//PRIVATE STATIC FUNCTION

int	AForm::validateGrade(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	return (grade);
}
