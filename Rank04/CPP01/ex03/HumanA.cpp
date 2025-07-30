/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:21:07 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/07/30 20:37:27 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanA.hpp"
# include "Weapon.hpp"
# include <iostream>

//CONSTRUCTOR

HumanA::HumanA(const std::string &name, Weapon &weapon) : name(name), weapon(weapon) {}

// PUBLIC METHODS

void	HumanA::attack(void)
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
