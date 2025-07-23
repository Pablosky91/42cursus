/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:12:30 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/07/23 20:01:30 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

//CONSTRUCTOR

Zombie::Zombie(std::string name)
{
	this->name = name;
}

//DESTRUCTOR

Zombie::~Zombie(void)
{
	std::cout << name << " destructed" << std::endl;
}

// PUBLIC METHODS

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
