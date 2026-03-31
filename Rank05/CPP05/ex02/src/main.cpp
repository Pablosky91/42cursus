/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 19:54:01 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/03/31 19:54:02 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int	main(void)
{
	Bureaucrat	good("Bernard", 1);
	Bureaucrat	avg("Daryl", 70);
	Bureaucrat	bad("Francis", 150);

	ShrubberyCreationForm		tree("home");
	RobotomyRequestForm			robot("Robert");
	PresidentialPardonForm		pardon("Baddie");

	bad.executeForm(tree);
	bad.signForm(tree);
	avg.signForm(tree);
	bad.executeForm(tree);
	avg.executeForm(tree);
	std::cout << '\n';

	bad.executeForm(robot);
	bad.signForm(robot);
	avg.signForm(robot);
	bad.executeForm(robot);
	avg.executeForm(robot);
	good.executeForm(robot);
	std::cout << '\n';

	bad.executeForm(pardon);
	bad.signForm(pardon);
	avg.signForm(pardon);
	good.signForm(pardon);
	bad.executeForm(pardon);
	avg.executeForm(pardon);
	good.executeForm(pardon);

	return (0);
}
