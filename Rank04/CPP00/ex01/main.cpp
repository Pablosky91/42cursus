/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 09:17:42 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/02/05 20:00:58 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>

bool	prompt(std::string *command)
{
	std::cout << std::endl << "Available commands: ADD, SEARCH, EXIT" ;
	std::cout << std::endl << "Your choice: ";
	if (std::getline(std::cin, *command))
		return (true);
	std::cout << std::endl;
	return (false);
}

int	main(void)
{
	std::string	command;
	Phonebook	phonebook;

	std::cout << "Welcome to your crappy awesome phonebook!" << std::endl;
	while (prompt(&command))
	{
		if (command == "ADD" && !phonebook.add())
			break ;
		else if (command == "SEARCH" && !phonebook.search())
			break ;
		else if (command == "EXIT")
			break ;
	}
	std::cout << "Have a nice day!" << std::endl;
	return (0);
}
