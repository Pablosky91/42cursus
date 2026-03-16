/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooLowException.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:55:36 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/03/16 13:55:37 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <exception>

class GradeTooLowException: public std::exception
{
	public:
		virtual const char	*what() const throw();
};
