/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 21:26:45 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/04/26 22:22:04 by pdel-olm         ###   ########.fr       */
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

//PUBLIC STATIC FUNCTION

void ScalarConverter::convert(std::string literal)
{
	std::cout << literal << " ";
	switch (getType(literal))
	{
	case 0:
		std::cout << "type: CHAR" << "\n";
		break;
	case 1:
		std::cout << "type: INT" << "\n";
		break;
	case 2:
		std::cout << "type: FLOAT" << "\n";
		break;
	case 3:
		std::cout << "type: DOUBLE" << "\n";
		break;
	case 4:
		std::cout << "type: ERROR" << "\n";
		break;
	default:
		std::cout << "type: SOMETHING WEIRD HAPPENED" << "\n";
		break;
	}
}
