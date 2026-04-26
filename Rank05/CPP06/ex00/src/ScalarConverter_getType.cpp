/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter_getType.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 20:56:13 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/04/26 22:27:51 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool	isInt(std::string literal);
static bool	isChar(std::string literal);
static bool	isFloat(std::string literal);
static bool	isDouble(std::string literal);

Type	ScalarConverter::getType(std::string literal)
{
	if (literal.empty())
		return (ERROR);
	if (isInt(literal))
		return (INT);
	if (isChar(literal))
		return (CHAR);
	if (isFloat(literal))
		return (FLOAT);
	if (isDouble(literal))
		return (DOUBLE);
	return (ERROR);
}

static bool	isInt(std::string literal)
{
	size_t	i = -1;

	if (literal[0] == '+' || literal[0] == '-')
		i++;
	while (++i < literal.length())
		if (literal[i] < '0' || literal[i] > '9')
			return (false);
	return (true);
}

static bool	isChar(std::string literal)
{
	if (literal.length() == 1 && literal[0] >= 32 && literal[0] <= 126)
		return (true);
	if (literal == "'''")
		return (false);
	if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
		return (true);
	if (literal == "'\\''")
		return (true);
	return (false);
}

static bool	isFloat(std::string literal)
{
	size_t	i = 0;

	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		return (true);
	if (literal[0] == '+' || literal[0] == '-')
		i++;
	if (literal[i] < '0' || literal[i] > '9')
		return (false);
	while (i < literal.length() && literal[i] >= '0' && literal[i] <= '9')
		i++;
	if (literal[i++] != '.')
		return (false);
	if (literal[i] < '0' || literal[i] > '9')
		return (false);
	while (i < literal.length() && literal[i] >= '0' && literal[i] <= '9')
		i++;
	if (literal[i++] != 'f')
		return (false);
	return (i == literal.length());
}

static bool	isDouble(std::string literal)
{
	size_t	i = 0;

	if (literal == "-inf" || literal == "+inf" || literal == "nan")
		return (true);
	if (literal[0] == '+' || literal[0] == '-')
		i++;
	if (literal[i] < '0' || literal[i] > '9')
		return (false);
	while (i < literal.length() && literal[i] >= '0' && literal[i] <= '9')
		i++;
	if (literal[i++] != '.')
		return (false);
	if (literal[i] < '0' || literal[i] > '9')
		return (false);
	while (i < literal.length() && literal[i] >= '0' && literal[i] <= '9')
		i++;
	return (i == literal.length());
}
