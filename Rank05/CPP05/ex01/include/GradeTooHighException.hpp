/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooHighException.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:55:31 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/03/16 13:55:32 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <exception>

class GradeTooHighException: public std::exception
{
	public:
		virtual const char	*what() const throw();
};
