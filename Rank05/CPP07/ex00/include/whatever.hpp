/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 18:16:50 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/06/23 18:47:46 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void	swap(T &a, T &b)
{
	T	c;

	c = a;
	a = b;
	b = c;
}

template <typename T>
T	min(const T &a, const T &b)
{
	return (a < b ? a : b);
}

template <typename T>
T	max(const T &a, const T &b)
{
	return (a > b ? a : b);
}

#endif
