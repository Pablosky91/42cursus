/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 21:43:12 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/04/01 22:10:53 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

int	main(void)
{
	Bureaucrat	bureaucrat("Bernard", 1);
	Intern		intern;
	AForm		*form = NULL;
	
	form = intern.makeForm("presidential pardon", "Baddie");
	bureaucrat.executeForm(*form);
	bureaucrat.signForm(*form);
	bureaucrat.executeForm(*form);
	delete(form);
	std::cout << '\n';

	form = intern.makeForm("robotomy request", "Robert");
	bureaucrat.executeForm(*form);
	bureaucrat.signForm(*form);
	bureaucrat.executeForm(*form);
	delete(form);
	std::cout << '\n';

	form = intern.makeForm("shrubbery creation", "home");
	bureaucrat.executeForm(*form);
	bureaucrat.signForm(*form);
	bureaucrat.executeForm(*form);
	delete(form);
	std::cout << '\n';

	form = intern.makeForm("something else", "whatever");

	return (0);
}
