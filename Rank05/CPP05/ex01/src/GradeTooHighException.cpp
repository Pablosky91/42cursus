/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooHighException.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:55:55 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/03/16 13:55:56 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GradeTooHighException.hpp"

const char	*GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}
