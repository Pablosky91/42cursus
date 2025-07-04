/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:11:26 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/07/04 12:51:29 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

// PUBLIC METHODS

bool	Contact::add(void)
{
	if (!set_field(&first_name, "first name"))
		return (false);
	if (!set_field(&last_name, "last name"))
		return (false);
	if (!set_field(&nickname, "nickname"))
		return (false);
	if (!set_field(&phone_number, "phone number"))
		return (false);
	if (!set_field(&darkest_secret, "darkest secret"))
		return (false);
	return (true);
}

void	Contact::display(void)
{
	std::cout << "First name: " << first_name << std::endl;
	std::cout << "Last name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phone_number << std::endl;
	std::cout << "Darkest secret: " << darkest_secret << std::endl;
}

std::string	Contact::get_first_name_short(void)
{
	return (get_field_short(first_name));
}

std::string	Contact::get_last_name_short(void)
{
	return (get_field_short(last_name));
}

std::string	Contact::get_nickname_short(void)
{
	return (get_field_short(nickname));
}

// PRIVATE METHODS

bool	Contact::set_field(std::string *field, std::string name)
{
	while (true)
	{
		std::cout << "Enter " << name << ": ";
		if (!std::getline(std::cin, *field))
		{
			std::cout << std::endl;
			return (false);
		}
		if (!(*field).empty())
			break ;
		std::cout << "Contacts can't have empty fields" << std::endl;
	}
	return (true);
}

std::string	Contact::get_field_short(std::string field)
{
	if (field.length() <= 10)
		return (field);
	return (field.substr(0, 9) + '.');
}
