/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 19:22:16 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/07/03 21:09:38 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void	multiply(int &n);

int	main(void)
{
	int					nums[] = {1, 2, 3, 4, 5};
	const std::string	words[] = {"one", "two", "three", "four"};

	::iter(nums, 5, print<int>);
	std::cout << std::endl;

	::iter(words, 4, print<const std::string>);
	std::cout << std::endl;

	::iter(nums, 3, multiply);
	::iter(nums, 5, print<int>);
	std::cout << std::endl;

	return (0);
}

void	multiply(int &n)
{
	n *= 10;
}
