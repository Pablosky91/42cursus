/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 21:41:21 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/01/18 22:40:06 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"

void	compare(Fixed a, Fixed b, std::string operation, bool boolean)
{
	std::string	color = boolean ? GREEN : RED;

	std::cout << color << a << operation << b << std::endl << RESET;
}

int	main(void)
{
	Fixed a(3);
	Fixed b(2);
	Fixed const c(4);
	Fixed const d(5);

	compare(a, b, " < ", a < b);
	compare(a, a, " < ", a < a);
	compare(a, b, " > ", a > b);
	compare(a, a, " > ", a > a);
	compare(a, b, " <= ", a <= b);
	compare(a, a, " <= ", a <= a);
	compare(a, b, " >= ", a >= b);
	compare(a, a, " >= ", a >= a);
	compare(a, b, " == ", a == b);
	compare(a, a, " == ", a == a);
	compare(a, b, " != ", a != b);
	compare(a, a, " != ", a != a);

	std::cout << std::endl;
	std::cout << a << " + " << b << " = " << (a + b) << std::endl;
	std::cout << a << " - " << b << " = " << (a - b) << std::endl;
	std::cout << a << " * " << b << " = " << (a * b) << std::endl;
	std::cout << a << " / " << b << " = " << (a / b) << std::endl;

	std::cout << std::endl;
	std::cout <<  "Pre-increment of " << a << " (" << ++a << ") to " << a << std::endl;
	std::cout << "Post-increment of " << a << " (" << a++ << ") to " << a << std::endl;
	std::cout <<  "Pre-decrement of " << a << " (" << --a << ") to " << a << std::endl;
	std::cout << "Post-decrement of " << a << " (" << a-- << ") to " << a << std::endl;

	std::cout << std::endl;
	std::cout << "Max between " << a << " and " << b << ": " << Fixed::max(a, b) << std::endl;
	std::cout << "Min between " << a << " and " << b << ": " << Fixed::min(a, b) << std::endl;
	std::cout << "Max between " << c << " and " << d << ": " << Fixed::max(c, d) << std::endl;
	std::cout << "Min between " << c << " and " << d << ": " << Fixed::min(c, d) << std::endl;
	std::cout << "Max between " << a << " and " << c << ": " << Fixed::max(a, c) << std::endl;
	std::cout << "Min between " << a << " and " << c << ": " << Fixed::min(a, c) << std::endl;

	return (0);
}
