/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:11:30 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/07/04 12:50:28 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>

// CONSTRUCTOR

Phonebook::Phonebook(void)
{
	contact_count = 0;
}

// PUBLIC METHODS

bool	Phonebook::add(void)
{
	if (contact_count < MAX_CONTACTS)
	{
		if (!contacts[contact_count++].add())
			return (false);
		return (true);
	}
	for (int i = 0; i < contact_count - 1; i++)
		contacts[i] = contacts[i + 1];
	if (!contacts[contact_count - 1].add())
		return (false);
	return (true);
}

bool	Phonebook::search(void)
{
	std::string	input;
	int			number = 0;

	if (contact_count == 0)
	{
		std::cout << "You have no contacts saved. Please use ADD." << std::endl;
		return (true) ;
	}
	display_table();
	while (true)
	{
		std::cout << "Index of the contact to display: ";
		if (!std::getline(std::cin, input))
		{
			std::cout << std::endl;
			return (false);
		}
		number = atoi(input.c_str());
		if (number > 0 && number <= contact_count)
			break ;
		std::cout << "Please enter a numeric value between 1 and " << contact_count << std::endl;
	}
	contacts[number - 1].display();
	return (true);
}

// PRIVATE METHODS

void	Phonebook::display_table(void)
{
	std::cout << std::endl;
	display_row("Index", "First name", "Last name", "Nickname");
	display_row("----------", "----------", "----------", "----------");
	for (int i = 0; i < contact_count; i++)
		display_row(i + 1, contacts[i].get_first_name_short(), contacts[i].get_last_name_short(), contacts[i].get_nickname_short());
	std::cout << std::endl;
}

void	Phonebook::display_row(std::string str0, std::string str1, std::string str2, std::string str3)
{
	std::cout << "|" << std::setw(10) << str0;
	std::cout << "|" << std::setw(10) << str1;
	std::cout << "|" << std::setw(10) << str2;
	std::cout << "|" << std::setw(10) << str3;
	std::cout << "|" << std::endl;
}

void	Phonebook::display_row(int row, std::string str1, std::string str2, std::string str3)
{
	std::cout << "|" << std::setw(10) << row;
	std::cout << "|" << std::setw(10) << str1;
	std::cout << "|" << std::setw(10) << str2;
	std::cout << "|" << std::setw(10) << str3;
	std::cout << "|" << std::endl;
}
