/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stopwatch.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 23:54:14 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/09/09 20:59:16 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STOPWATCH_HPP
# define STOPWATCH_HPP

# include <sys/time.h>

class Stopwatch
{
	public:
		Stopwatch();
		Stopwatch(const Stopwatch &other);
		~Stopwatch();
		Stopwatch	&operator =(const Stopwatch &other);
		
		void	start();
		double	stop();
		double	get_time();

	private:
		timeval	_start;
		timeval	_end;
};

#endif
