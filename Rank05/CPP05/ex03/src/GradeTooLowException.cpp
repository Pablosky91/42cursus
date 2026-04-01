/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooLowException.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 21:43:18 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/03/31 21:43:19 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GradeTooLowException.hpp"

const char	*GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}
