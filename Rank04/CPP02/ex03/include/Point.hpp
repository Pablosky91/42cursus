/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 23:31:04 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/01/19 19:36:31 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(float const x, float const y);
		Point(const Point& other);
		~Point();
		Point	&operator =(const Point &other);

		Fixed	getX(void) const;
		Fixed	getY(void) const;

	private:
		Fixed const	_x;
		Fixed const	_y;
	};

std::ostream	&operator<<(std::ostream &ostream, const Point &point);
bool			bsp(Point const a, Point const b, Point const c, Point const point);

#endif
