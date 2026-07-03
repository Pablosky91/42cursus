/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 13:40:00 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/06/22 10:20:45 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

//DEFAULT CONSTRUCTOR

Serializer::Serializer()
{
}

//COPY CONSTRUCTOR

Serializer::Serializer(const Serializer &other)
{
	*this = other;
}

//DESTRUCTOR

Serializer::~Serializer()
{
}

//COPY ASSIGNMENT OPERATOR

Serializer	&Serializer::operator =(const Serializer &other)
{
	if (this != &other)
		;
	return (*this);
}

//PUBLIC METHODS

uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
