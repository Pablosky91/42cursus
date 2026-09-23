/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stopwatch.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 23:54:17 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/09/09 20:05:47 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Stopwatch.hpp"

//DEFAULT CONSTRUCTOR

Stopwatch::Stopwatch()
{
	start();
}

//COPY CONSTRUCTOR

Stopwatch::Stopwatch(const Stopwatch& other)
{
	*this = other;
}

//DESTRUCTOR

Stopwatch::~Stopwatch()
{
}

//COPY ASSIGNMENT OPERATOR

Stopwatch	&Stopwatch::operator =(const Stopwatch &other)
{
	if (this != &other)
	{
		_start = other._start;
		_end = other._end;
	}
	return (*this);
}

//PUBLIC MEMBER FUNCTIONS

void	Stopwatch::start()
{
	gettimeofday(&_start, 0);
}

double	Stopwatch::stop()
{
	gettimeofday(&_end, 0);
	return (get_time());
}

double	Stopwatch::get_time()
{
	return ((_end.tv_sec - _start.tv_sec) * 1000 + (_end.tv_usec - _start.tv_usec) / 1000.0);
}
