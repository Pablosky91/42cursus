/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 22:20:19 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/01/31 01:06:24 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	clap("Caroline");
	ScavTrap	scav("Sebastian");

	std::cout << std::endl;
	clap.print();
	clap.attack("Clint");
	clap.takeDamage(1000);
	clap.attack("Clint");
	clap.print();

	std::cout << std::endl;
	scav.print();
	scav.attack("Sam");
	scav.guardGate();
	scav.takeDamage(1000);
	scav.attack("Sam");
	scav.print();

	std::cout << std::endl;
	return (0);
}
