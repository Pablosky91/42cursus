/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooHighException.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 21:44:11 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/03/31 21:44:12 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <exception>

class GradeTooHighException: public std::exception
{
	public:
		virtual const char	*what() const throw();
};
