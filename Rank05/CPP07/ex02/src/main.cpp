/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 11:50:42 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/07/09 11:20:19 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

template <typename T>
void	print_array(std::string str, Array<T> &arr)
{
	std::cout << str << std::endl;
	for (size_t i = 0; i < arr.size(); i++)
		std::cout << i << " -> "<< arr[i] << std::endl;
}

#define MAX_VAL 750
int	main(void)
{
	Array<int>	*arr = new Array<int>(5);
	
	std::cout << "Size: " << arr->size() << std::endl;
	print_array("Empty:", (*arr));
	
	for (size_t i = 0; i < arr->size(); i++)
		(*arr)[i] = 50 - 10 * i;
	print_array("Numbers:", (*arr));
	
	Array<int>	copy(*arr);
	print_array("Copy:", copy);

	for (size_t i = 0; i < arr->size(); i++)
		(*arr)[i] = (*arr)[i] / 5;
	print_array("Original after modification:", (*arr));
	print_array("Copy after modifying original:", copy);

	copy = *arr;
	print_array("Copy after copying again:", copy);

	try
	{
		std::cout << "First position: "<< copy[0] << std::endl;
		std::cout << "Impossible position: "<< copy[5] << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << "Index out of bounds" << std::endl;
	}

	Array<std::string>	strs(3);
	strs[0] = "Hi";
	strs[1] = "There";
	strs[2] = "Hello";
	print_array("Strings:", strs);

	delete arr;
	return (0);
}
