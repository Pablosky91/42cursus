/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 21:26:45 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/06/30 20:12:35 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cmath>
#include <iomanip>
#include <sstream>

static Scalars	init_scalars(std::string literal);
static Type		getType(const std::string &literal);
static void		convertToType(Scalars *scalars);
static void		convertToOtherTypes(Scalars *scalars);
static void		displayScalars(const Scalars &scalars);

//DEFAULT CONSTRUCTOR

ScalarConverter::ScalarConverter()
{
}

//COPY CONSTRUCTOR

ScalarConverter::ScalarConverter(const ScalarConverter &other)
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

//PUBLIC STATIC FUNCTION

void	ScalarConverter::convert(std::string literal)
{
	Scalars	scalars = init_scalars(literal);

	convertToType(&scalars);
	convertToOtherTypes(&scalars);
	displayScalars(scalars);
}

//STATIC PRIVATE FUNCTION

static Scalars	init_scalars(std::string literal)
{
	Scalars	scalars;

	scalars.literal = literal;
	scalars.type = getType(literal);
	scalars.is_special = true;
	scalars.char_value = 0;
	scalars.int_value = 0;
	scalars.float_value = 0;
	scalars.double_value = 0;
	return (scalars);
}

//GET TYPE

static bool	isInt(const std::string &literal);
static bool	isChar(const std::string &literal);
static bool	isFloat(const std::string &literal);
static bool	isDouble(const std::string &literal);

static Type	getType(const std::string &literal)
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

static bool	isInt(const std::string &literal)
{
	size_t	i = -1;

	if (literal[0] == '+' || literal[0] == '-')
		i++;
	while (++i < literal.length())
		if (literal[i] < '0' || literal[i] > '9')
			return (false);
	return (true);
}

static bool	isChar(const std::string &literal)
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

static bool	isFloat(const std::string &literal)
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

static bool	isDouble(const std::string &literal)
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

//CONVERT TO TYPE

static void	convertToChar(Scalars *scalars);
static void	convertToInt(Scalars *scalars, std::stringstream *ss);
static void	convertToFloat(Scalars *scalars, std::stringstream *ss);
static void	convertToDouble(Scalars *scalars, std::stringstream *ss);

static void	convertToType(Scalars *scalars)
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

//CONVERT TO OTHER TYPES

static void	convertFromChar(Scalars *scalars);
static void	convertFromInt(Scalars *scalars);
static void	convertFromFloat(Scalars *scalars);
static void	convertFromDouble(Scalars *scalars);

static void	convertToOtherTypes(Scalars *scalars)
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

//DISPLAY SCALARS

static void	displayChar(const Scalars &scalars);
static void	displayInt(const Scalars &scalars);
static void	displayFloat(const Scalars &scalars);
static void	displayDouble(const Scalars &scalars);

static void	displayScalars(const Scalars &scalars)
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
	else if (scalars.char_value == '\'')
		std::cout << "'\\''\n";
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
