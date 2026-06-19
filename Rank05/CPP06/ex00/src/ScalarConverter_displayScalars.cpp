/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter_displayScalars.cpp                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 15:08:50 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/05/23 21:33:13 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cmath>
#include <iomanip>

static void	displayChar(const Scalars &scalars);
static void	displayInt(const Scalars &scalars);
static void	displayFloat(const Scalars &scalars);
static void	displayDouble(const Scalars &scalars);

void	ScalarConverter::displayScalars(const Scalars &scalars)
{
	if (scalars.float_value == floor(scalars.float_value))
		std::cout << std::fixed << std::setprecision(1);
	displayChar(scalars);
	displayInt(scalars);
	displayFloat(scalars);
	displayDouble(scalars);
}

static void	displayChar(const Scalars &scalars)
{
	std::cout << "char: ";
	if (scalars.type == ERROR || scalars.is_special)
		std::cout << "impossible\n";
	else if (scalars.char_value < 32 || scalars.char_value > 126)
		std::cout << "Non displayable\n";
	else
		std::cout << "'" << scalars.char_value <<"'\n";
}

static void	displayInt(const Scalars &scalars)
{
	std::cout << "int: ";
	if (scalars.type == ERROR || scalars.is_special || scalars.double_value > std::numeric_limits<int>::max() || scalars.double_value < std::numeric_limits<int>::min())
		std::cout << "impossible\n";
	else
		std::cout << scalars.int_value << "\n";
}

static void	displayFloat(const Scalars &scalars)
{
	std::cout << "float: ";
	if (scalars.type == ERROR)
		std::cout << "impossible\n";
	else
		std::cout << scalars.float_value << "f\n";
}

static void	displayDouble(const Scalars &scalars)
{
	std::cout << "double: ";
	if (scalars.type == ERROR)
		std::cout << "impossible\n";
	else
		std::cout << scalars.double_value << "\n";
}
