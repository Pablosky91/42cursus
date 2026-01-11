/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:25:09 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/01/11 20:09:10 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	Harl				harl;
	int					level;
	const std::string	levels[Harl::N_LEVELS] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	if (argc != 2)
	{
		std::cerr << "Pass as a parameter one of the following: DEBUG / INFO / WARNING / ERROR" << std::endl << std::endl;
		return (1);
	}
	for (level = 0; level < Harl::N_LEVELS && levels[level] != argv[1]; level++) ;
	switch (level)
	{
	case 0:
		std::cout << "[ DEBUG ]" << std::endl;
		harl.complain("DEBUG");
		std::cout << std::endl;
	case 1:
		std::cout << "[ INFO ]" << std::endl;
		harl.complain("INFO");
		std::cout << std::endl;
	case 2:
		std::cout << "[ WARNING ]" << std::endl;
		harl.complain("WARNING");
		std::cout << std::endl;
	case 3:
		std::cout << "[ ERROR ]" << std::endl;
		harl.complain("ERROR");
		std::cout << std::endl;
		break ;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl << std::endl;
	}
	return (0);
}
