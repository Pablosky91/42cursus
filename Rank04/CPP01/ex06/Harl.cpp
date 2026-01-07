/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:25:03 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/01/07 12:10:01 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

//PUBLIC METHODS

void	Harl::complain(std::string level)
{
	static t_HarlMap	map;
	t_HarlMap::iterator	it;

	if (map.empty())
	{
		map["DEBUG"] = &Harl::debug;
		map["INFO"] = &Harl::info;
		map["WARNING"] = &Harl::warning;
		map["ERROR"] = &Harl::error;
	}
	it = map.find(level);
	if (it != map.end())
		(this->*(it->second))();
	else
		std::cout << "Probably complaining about insignificant problems." << std::endl;
}

//PRIVATE METHODS

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
