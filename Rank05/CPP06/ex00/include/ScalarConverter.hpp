/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 21:26:42 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/04/26 22:18:36 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <limits>

enum Type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	ERROR,
};

const float NANF = std::numeric_limits<float>::quiet_NaN();
const float INFF = std::numeric_limits<float>::infinity();
const float NINFF = -std::numeric_limits<float>::infinity();

const double NAN = std::numeric_limits<double>::quiet_NaN();
const double INF = std::numeric_limits<double>::infinity();
const double NINF = -std::numeric_limits<double>::infinity();

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter	&operator =(const ScalarConverter &other);

		static void	convert(std::string literal);

	private:
		~ScalarConverter();

		static Type	getType(std::string literal);
};

#endif
