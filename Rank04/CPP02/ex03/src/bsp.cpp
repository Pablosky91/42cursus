/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 23:35:22 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/01/19 20:41:34 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

static bool		same_side(Fixed const a, Fixed const b, Fixed const c);
static Fixed	cross(Point const a, Point const b, Point const c);

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	return (same_side(cross(a, b, point), cross(b, c, point), cross(c, a, point)));
}

//Returns true when all positive or all negative
static bool	same_side(Fixed const a, Fixed const b, Fixed const c)
{
	return ((a > 0 && b > 0 && c > 0) || (a < 0 && b < 0 && c < 0));
}

//Cross product of AB x AC
static Fixed	cross(Point const a, Point const b, Point const c)
{
	return ((b.getX() - a.getX()) * (c.getY() - a.getY()) - (b.getY() - a.getY()) * (c.getX() - a.getX()));
}
