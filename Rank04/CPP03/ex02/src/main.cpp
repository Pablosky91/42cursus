/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:26:20 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/02/02 11:43:45 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap	clap("Caroline");
	ScavTrap	scav("Sebastian");
	FragTrap	frag("Fizz");

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
	frag.print();
	frag.attack("Buzz");
	frag.highFivesGuys();
	frag.takeDamage(1000);
	frag.attack("Buzz");
	frag.print();

	std::cout << std::endl;
	return (0);
}
