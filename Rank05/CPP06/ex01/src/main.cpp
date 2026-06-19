/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 13:40:15 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/06/22 10:35:31 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int	main(void)
{
	Data		*data = new Data();
	Data		*copy = NULL;
	uintptr_t	raw;

	data->id = 1;
	data->value = 4.2;
	std::cout << "Data (" << data->id << "): " << data->value << " at " << data << "\n";
	
	raw = Serializer::serialize(data);
	std::cout << "Serial number: " << raw << "\n";
	
	copy = Serializer::deserialize(raw);
	std::cout << "Data (" << copy->id << "): " << copy->value << " at " << data <<  "\n";
	
	std::cout << std::boolalpha << "Same address: " << (data == copy) <<  "\n";

	delete data;
	return (0);
}
