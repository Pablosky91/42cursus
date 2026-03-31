/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 18:25:03 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/03/18 17:49:18 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int	main(void)
{
	Bureaucrat	empty;
	Bureaucrat	named("Bernard");
	Bureaucrat	graded(42);
	Bureaucrat	both("Francis", 147);
	Bureaucrat	copy(both);

	std::cout << empty << named << graded << both << copy << "\n";

	try
	{
		for (size_t i = 0; i < 5; i++)
		{
			both.decrement();
			std::cout << both;
		}
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << "\n\n";
	}

	try
	{
		Bureaucrat	so_good(0);
		std::cout << so_good;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << "\n\n";
	}

	try
	{
		named.setGrade(300);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << "\n\n";
	}

	return (0);
}
