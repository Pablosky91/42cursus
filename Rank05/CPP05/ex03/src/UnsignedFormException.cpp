/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UnsignedFormException.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 21:42:38 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/03/31 21:42:40 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UnsignedFormException.hpp"

const char	*UnsignedFormException::what() const throw()
{
	return ("Unsigned form");
}
