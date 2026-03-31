/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:25:47 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/03/18 17:49:25 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main(void)
{
	Bureaucrat	b1("Bernard", 42);
	Bureaucrat	b2("Francis", 150);
	Form		empty;
	Form		named("28B");
	Form		graded(4, 2);
	Form		both("28C", 42, 84);
	Form		copy(both);

	std::cout << empty << named << graded << both << copy << "\n";

	try
	{
		Form	bad(0, 151);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << "\n\n";
	}

	b2.signForm(both);
	std::cout << b2 << both << "\n";
	b1.signForm(both);
	std::cout << b1 << both << "\n";

	b2.signForm(both);
	b1.signForm(both);

	return (0);
}
