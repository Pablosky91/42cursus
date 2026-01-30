/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 18:13:11 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/01/30 21:06:02 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	dead("Albert");
	ClapTrap	exhausted("Bernie");

	dead.takeDamage(10);
	dead.print();
	dead.attack("nothing");
	dead.takeDamage(1);
	dead.beRepaired(1);

	for (int i = 0; i < 5; i++)
	{
		exhausted.attack("Dummy");
		exhausted.beRepaired(18);
		exhausted.print();
	}
	exhausted.attack("nothing");
	exhausted.takeDamage(1);
	exhausted.beRepaired(1);

	return (0);
}
