/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 11:56:37 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/08/20 16:26:42 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <sstream>

int	main(int argc, char **argv)
{
	std::istringstream	iss;
	std::string			token;
	RPN					rpn;

	if (argc == 1)
	{
		std::cerr << "Pass an inverted polish mathematical expression as an argument" << std::endl;
		return (1);
	}
	try
	{
		for (int i = 1; i < argc; i++)
		{
			iss.str(argv[i]);
			while (iss >> token)
				rpn.new_token(token);
			iss.clear();
		}
		std::cout << rpn.get_result() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
