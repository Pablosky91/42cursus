/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooLowException.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 21:44:05 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/03/31 21:44:06 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <exception>

class GradeTooLowException: public std::exception
{
	public:
		virtual const char	*what() const throw();
};
