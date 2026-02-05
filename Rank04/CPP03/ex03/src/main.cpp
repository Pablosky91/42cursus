/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:53:21 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/02/05 19:53:26 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	diamond("Demetrius");

	std::cout << std::endl;
	diamond.print();
	diamond.attack("Dwarf");
	diamond.guardGate();
	diamond.highFivesGuys();
	diamond.whoAmI();
	diamond.takeDamage(1000);
	diamond.attack("Dwarf");
	diamond.print();

	std::cout << std::endl;
	return (0);
}
