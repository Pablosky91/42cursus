/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 13:15:38 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/04/26 22:22:37 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

// #include <cmath>
#include <limits>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error\nUsage: " << argv[0] << " parameter\n";
		return (1);
	}
	ScalarConverter::convert(argv[1]);

	return (0);
}
