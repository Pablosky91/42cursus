/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter_convertToType.cpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 15:03:04 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/05/23 21:14:33 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <sstream>

static void	convertToChar(Scalars *scalars);
static void	convertToInt(Scalars *scalars, std::stringstream *ss);
static void	convertToFloat(Scalars *scalars, std::stringstream *ss);
static void	convertToDouble(Scalars *scalars, std::stringstream *ss);

void	ScalarConverter::convertToType(Scalars *scalars)
{
	std::stringstream	ss(scalars->literal);

	switch (scalars->type)
	{
	case CHAR:
		convertToChar(scalars);
		break;
	case INT:
		convertToInt(scalars, &ss);
		break;
	case FLOAT:
		convertToFloat(scalars, &ss);
		break;
	case DOUBLE:
		convertToDouble(scalars, &ss);
		break;
	default:
		;
	}
	if (ss.fail())
		scalars->type = ERROR;
}

static void	convertToChar(Scalars *scalars)
{
	scalars->is_special = false;
	if (scalars->literal == "'\\''")
		scalars->char_value = '\'';
	scalars->char_value = (scalars->literal[scalars->literal.length() == 3]);
}

static void	convertToInt(Scalars *scalars, std::stringstream *ss)
{
	scalars->is_special = false;
	*ss >> scalars->int_value;
}

static void	convertToFloat(Scalars *scalars, std::stringstream *ss)
{
	if (scalars->literal == "nanf")
		scalars->float_value = NANF;
	else if (scalars->literal == "+inff")
		scalars->float_value = INFF;
	else if (scalars->literal == "-inff")
		scalars->float_value = NINFF;
	else
	{
		scalars->is_special = false;
		*ss >> scalars->float_value;
	}
}

static void	convertToDouble(Scalars *scalars, std::stringstream *ss)
{
	if (scalars->literal == "nan")
		scalars->double_value = NAN;
	else if (scalars->literal == "+inf")
		scalars->double_value = INF;
	else if (scalars->literal == "-inf")
		scalars->double_value = NINF;
	else
	{
		scalars->is_special = false;
		*ss >> scalars->double_value;
	}
}
