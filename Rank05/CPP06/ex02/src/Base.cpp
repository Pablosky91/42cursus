/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 15:33:17 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/06/23 16:56:47 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

Base::~Base()
{
}

Base	*generate(void)
{
	switch (rand() % 3)
	{
	case 0:
		return (new A);
	case 1:
		return (new B);
	default:
		return (new C);
	}
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B *>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C *>(p))
		std::cout << "C\n";
}

void	identify(Base &p)
{
	try
	{
		(void) (dynamic_cast<A &>(p));
		std::cout << "A\n";
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		(void) (dynamic_cast<B &>(p));
		std::cout << "B\n";
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		(void) (dynamic_cast<C &>(p));
		std::cout << "C\n";
	}
	catch(const std::exception& e)
	{
	}
}
