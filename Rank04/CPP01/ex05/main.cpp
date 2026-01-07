/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 19:50:12 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/01/07 11:58:12 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main(void)
{
	Harl	harl;

	std::cout << "Harl debug: " << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl << "Harl info: " << std::endl;
	harl.complain("INFO");
	std::cout << std::endl << "Harl warning: " << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl << "Harl error: " << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl << "Harl else: " << std::endl;
	harl.complain("ELSE");
	return (0);
}
