/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:25:09 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/01/07 12:10:07 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <map>

int	main(int argc, char **argv)
{
	Harl									harl;
	std::map<std::string, int>				map;
	std::map<std::string, int>::iterator	it;
	int										level;

	if (argc != 2)
	{
		std::cerr << "Pass as a parameter one of the following: DEBUG / INFO / WARNING / ERROR" << std::endl;
		return (1);
	}
	map["DEBUG"] = 0;
	map["INFO"] = 1;
	map["WARNING"] = 2;
	map["ERROR"] = 3;
	it = map.find(argv[1]);
	level = it != map.end() ? it->second : -1;
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
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return (0);
}
