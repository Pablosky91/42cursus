/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 19:51:12 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/01/11 20:11:42 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

//PUBLIC METHODS

void	Harl::complain(std::string level)
{
	std::string	levels[N_LEVELS] =				{"DEBUG",		"INFO",			"WARNING",		"ERROR"};
	void (Harl::*functions[N_LEVELS])(void) =	{&Harl::debug,	&Harl::info,	&Harl::warning,	&Harl::error};

	for (int i = 0; i < N_LEVELS; i++)
	{
		if (level == levels[i])
		{
			(this->*functions[i])();
			return ;
		}
	}
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
