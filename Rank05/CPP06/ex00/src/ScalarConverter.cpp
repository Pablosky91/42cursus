/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 21:26:45 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/05/23 20:41:51 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

//DEFAULT CONSTRUCTOR

ScalarConverter::ScalarConverter()
{
}

//COPY CONSTRUCTOR

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	*this = other;
}

//DESTRUCTOR

ScalarConverter::~ScalarConverter()
{
}

//COPY ASSIGNMENT OPERATOR

ScalarConverter	&ScalarConverter::operator =(const ScalarConverter &other)
{
	if (this != &other)
		;
	return (*this);
}

//STATIC PRIVATE FUNCTION

static Scalars	init_scalars(std::string literal, Type type)
{
	Scalars	scalars;

	scalars.literal = literal;
	scalars.type = type;
	scalars.is_special = true;
	scalars.char_value = 0;
	scalars.int_value = 0;
	scalars.float_value = 0;
	scalars.double_value = 0;
	return (scalars);
}

//PUBLIC STATIC FUNCTION

void	ScalarConverter::convert(std::string literal)
{
	Scalars	scalars = init_scalars(literal, getType(literal));

	convertToType(&scalars);
	convertToOtherTypes(&scalars);
	displayScalars(scalars);
}
