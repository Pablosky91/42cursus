/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 22:13:15 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/07/16 23:03:40 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <sstream>

template <typename C>
typename C::const_iterator	easyfind(const C &container, int value)
{
	typename C::const_iterator	it;

	it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
	{
		std::ostringstream	oss;
		oss << "No " << value << " in container";
		throw std::runtime_error(oss.str());
	}
	return it;
}

#endif