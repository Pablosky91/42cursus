/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UnsignedFormException.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 21:43:44 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/03/31 21:43:45 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <exception>

class UnsignedFormException: public std::exception
{
	public:
		virtual const char	*what() const throw();
};
