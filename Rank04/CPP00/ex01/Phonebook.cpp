/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:11:30 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/06/28 22:04:13 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <cstdlib>
#include <iostream>

Phonebook::Phonebook(void)
{
	contact_count = 0;
}

bool	Phonebook::add(void)
{
	if (contact_count < 8)
	{
		if (!contacts->add())
			return (false);
		contact_count++;
	}
	return (true);
}

bool	Phonebook::search(void)
{
	if (contact_count == 0)
	{
		std::cout << "You have no contacts saved. Please use ADD." << std::endl;
		return (true) ;
	}
	//TODO table with existing contacts
	//TODO ask for index until in range (atoi)
	//TODO display indexed one
	contacts[0].display();
	return (true);
}
