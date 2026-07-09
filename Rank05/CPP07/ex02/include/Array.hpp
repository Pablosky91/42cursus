/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 11:39:13 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/07/06 13:26:19 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array
{
	public:
		Array();
		Array(unsigned long n);
		Array(const Array &other);
		Array	&operator =(const Array &other);
		T		&operator [](unsigned long position);
		~Array();

		unsigned long	size(void) const;
	private:
		unsigned long	_size;
		T				*_array;
};

# include "Array.tpp"

#endif