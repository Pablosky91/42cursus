/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 22:08:22 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/01/18 22:37:45 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	public:

		// CONSTRUCTORS

		Fixed();
		Fixed(const Fixed &other);
		~Fixed();

		// ASSIGNMENT OPERATOR

		Fixed	&operator =(const Fixed& other);

		// MEMEBER FUNCTIONS

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		static const int	kFractionalBits = 8;
		int					_value;
};

#endif
