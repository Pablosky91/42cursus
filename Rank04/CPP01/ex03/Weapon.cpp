/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:07:10 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/07/30 20:38:14 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

//CONSTRUCTOR

Weapon::Weapon(const std::string &type) : type(type) {}

// PUBLIC METHODS

const std::string	&Weapon::getType() const
{
	return (type);
}

void	Weapon::setType(const std::string	&type)
{
	this->type = type;
}
