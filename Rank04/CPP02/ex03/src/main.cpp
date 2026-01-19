/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 23:11:06 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/01/19 21:59:10 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define BLUE	"\033[34m"

void	check(Point const a, Point const b, Point const c, Point const point)
{
	if (bsp(a, b, c, point))
		std::cout << GREEN << "The point " << point << " is inside" << std::endl << RESET;
	else
		std::cout << RED << "The point " << point << " is outside" << std::endl << RESET;
}

int	main(void)
{
	Point const	a(0, 0);
	Point const	b(10, 0);
	Point const	c(0, 10);

	std::cout << BLUE << "Triangle " << a << " " << b << " " << c << std::endl << RESET;

	//VERTICES
	check(a, b, c, a);
	check(a, b, c, b);
	check(a, b, c, c);

	//EDGES
	check(a, b, c, Point(0, 3));
	check(a, b, c, Point(6, 0));
	check(a, b, c, Point(8, 2));

	//OUTSIDE
	check(a, b, c, Point(7, 7));
	check(a, b, c, Point(-5, 2));
	check(a, b, c, Point(5, -2));

	//INSIDE
	check(a, b, c, Point(1, 1));
	check(a, b, c, Point(8, 1));
	check(a, b, c, Point(1, 8));
	check(a, b, c, Point(3, 3));

	return (0);
}
