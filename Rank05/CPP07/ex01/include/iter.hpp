/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 19:22:05 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/07/03 21:02:48 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T, typename F>
void	iter(T *array, const  int length, F function)
{
	if (!array)
		return ;
	for (int i = 0; i < length; i++)
		function(array[i]);
}

template <typename T>
void	print(const T &n)
{
	std::cout << n << " ";
}

#endif
