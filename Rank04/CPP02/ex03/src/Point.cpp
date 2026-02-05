/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 23:31:08 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/02/05 20:08:20 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//DEFAULT CONSTRUCTOR

Point::Point(): _x(0), _y(0)
{}

//FLOATS CONSTRUCTOR

Point::Point(float const x, float const y): _x(x), _y(y)
{}

// COPY CONSTRUCTOR

Point::Point(const Point &other): _x(other._x), _y(other._y)
{}

//DESTRUCTOR

Point::~Point()
{}

//NON-FUNCTIONAL COPY ASSIGNMENT OPERATOR

Point	&Point::operator =(const Point &other)
{
	(void) other;
	return (*this);
}

//OUTPUT OPERATOR

std::ostream	&operator<<(std::ostream &ostream, const Point &point)
{
	ostream << "(" << point.getX() << ", " << point.getY() << ")";
	return (ostream);
}

//PUBLIC MEMBER FUNCTIONS

Fixed Point::getX(void) const
{
	return (_x);
}

Fixed Point::getY(void) const
{
	return (_y);
}
