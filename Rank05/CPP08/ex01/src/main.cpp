/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 13:15:20 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/07/25 13:24:58 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <iostream>

int	main(void)
{
	Span sp(5);
	Span sp2(10000);
	std::vector<int> values(10000);
	std::srand(time(0));

	try
	{
		sp.shortestSpan();
		sp.longestSpan();
	}
	catch(const std::exception &e)
	{
		std::cerr << "Span has less than 2 numbers\n";
	}

	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(20);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Span full\n";
	}

	try
	{
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << "Span has less than 2 numbers\n";
	}

	try
	{
		for (size_t i = 0; i < 10000; ++i)
			values[i] = std::rand();
		sp2.addRange(values.begin(), values.end());
	}
	catch(const std::exception &e)
	{
		std::cerr << "Span can't take so many numbers\n";
	}

	try
	{
		std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << "Span has less than 2 numbers\n";
	}
	return (0);
}
