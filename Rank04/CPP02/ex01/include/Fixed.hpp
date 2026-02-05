/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:15:36 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/02/05 20:14:01 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		// CONSTRUCTORS

		Fixed();
		Fixed(const Fixed &other);
		Fixed(const int value);
		Fixed(const float value);
		~Fixed();

		// ASSIGNMENT OPERATOR

		Fixed	&operator =(const Fixed &other);

		// MEMBER FUNCTIONS

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;

	private:
		static const int	kFractionalBits = 8;
		int					_value;
};

std::ostream	&operator<<(std::ostream &ostream, const Fixed &fixed);

#endif
