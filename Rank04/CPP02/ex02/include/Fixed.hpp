/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 21:41:08 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/02/05 20:12:31 by pdel-olm         ###   ########.fr       */
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

		// COMPARISON OPERATORS

		bool	operator <(const Fixed &other) const;
		bool	operator >(const Fixed &other) const;
		bool	operator <=(const Fixed &other) const;
		bool	operator >=(const Fixed &other) const;
		bool	operator ==(const Fixed &other) const;
		bool	operator !=(const Fixed &other) const;

		// ARITHMETIC OPERATORS
		
		Fixed	operator +(const Fixed &other) const;
		Fixed	operator -(const Fixed &other) const;
		Fixed	operator *(const Fixed &other) const;
		Fixed	operator /(const Fixed &other) const;

		// (IN|DE)CREMENT OPERATORS

		Fixed	&operator ++(void);
		Fixed	operator ++(int);
		Fixed	&operator --(void);
		Fixed	operator --(int);

		// MEMBER FUNCTIONS

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;

		static Fixed		&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);

	private:
		static const int	kFractionalBits = 8;
		int					_value;
};

std::ostream	&operator<<(std::ostream &ostream, const Fixed &fixed);

#endif
