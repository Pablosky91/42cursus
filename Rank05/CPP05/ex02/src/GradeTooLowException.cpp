/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooLowException.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 19:54:02 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/03/31 19:54:03 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GradeTooLowException.hpp"

const char	*GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}
