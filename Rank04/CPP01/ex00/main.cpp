/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:12:24 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/07/23 20:10:29 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include "Zombie.hpp"
#include <iostream>

int	main(void)
{
	Zombie *a;
	Zombie b("Berta");

	a = newZombie("Armando");
	a->announce();
	b.announce();
	randomChump("Carlos");
	delete a;
	return (0);
}
