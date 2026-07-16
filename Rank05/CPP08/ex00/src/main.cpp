/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 22:12:02 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/07/16 23:07:14 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <set>
#include <vector>

int	main(void)
{
	std::set<int>	set;
	set.insert(1);
	set.insert(2);
	set.insert(3);
	set.insert(1);
	try
	{
		std::cout << *(easyfind(set, 1)) << std::endl;
		std::cout << *(easyfind(set, 2)) << std::endl;
		std::cout << *(easyfind(set, 3)) << std::endl;
		std::cout << *(easyfind(set, 4)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::vector<int>	vector;
	vector.push_back(10);
	vector.push_back(20);
	vector.push_back(30);
	vector.push_back(10);
	try
	{
		std::cout << *(easyfind(vector, 10)) << std::endl;
		std::cout << *(easyfind(vector, 20)) << std::endl;
		std::cout << *(easyfind(vector, 30)) << std::endl;
		std::cout << *(easyfind(vector, 40)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
