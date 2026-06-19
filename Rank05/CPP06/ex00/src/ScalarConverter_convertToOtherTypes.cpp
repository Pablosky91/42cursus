/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter_convertToOtherTypes.cpp            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 19:40:32 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/05/23 21:44:59 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static void	convertFromChar(Scalars *scalars);
static void	convertFromInt(Scalars *scalars);
static void	convertFromFloat(Scalars *scalars);
static void	convertFromDouble(Scalars *scalars);

void	ScalarConverter::convertToOtherTypes(Scalars *scalars)
{
	switch (scalars->type)
	{
	case CHAR:
		convertFromChar(scalars);
		break;
	case INT:
		convertFromInt(scalars);
		break;
	case FLOAT:
		convertFromFloat(scalars);
		break;
	case DOUBLE:
		convertFromDouble(scalars);
		break;
	default:
		;
	}
}

static void	convertFromChar(Scalars *scalars)
{
	scalars->int_value = static_cast<int>(scalars->char_value);
	scalars->float_value = static_cast<float>(scalars->char_value);
	scalars->double_value = static_cast<double>(scalars->char_value);
}

static void	convertFromInt(Scalars *scalars)
{
	scalars->char_value = static_cast<char>(scalars->int_value);
	scalars->float_value = static_cast<float>(scalars->int_value);
	scalars->double_value = static_cast<double>(scalars->int_value);
}

static void	convertFromFloat(Scalars *scalars)
{
	scalars->char_value = static_cast<char>(scalars->float_value);
	scalars->int_value = static_cast<int>(scalars->float_value);
	scalars->double_value = static_cast<double>(scalars->float_value);
}

static void	convertFromDouble(Scalars *scalars)
{
	scalars->char_value = static_cast<char>(scalars->double_value);
	scalars->int_value = static_cast<int>(scalars->double_value);
	scalars->float_value = static_cast<float>(scalars->double_value);
}
