/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 19:05:39 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/08/01 22:25:15 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

int	main(int argc, char **argv)
{
	BitcoinExchange		btc;
	std::ifstream		data("data.csv");
	std::ifstream		input(argv[1]);
	std::istringstream	iss;
	std::string			line;

	if (argc != 2)
	{
		std::cerr << "Pass an input file as the only argument" << std::endl;
		return (1);
	}

	if (!data.is_open())
	{
		std::cerr << "Can't load bitcoin prices: file data.csv is missing" << std::endl;
		return (1);
	}

	try
	{
		btc.loadDatabase(data);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Can't load bitcoin prices: error in file data.csv:\n\t" << e.what() << std::endl;
		return (1);
	}

	if (!input.is_open())
	{
		std::cerr << "Can't open file " << argv[1] << std::endl;
		return (1);
	}

	std::getline(input, line);
	while(std::getline(input, line))
	{
		iss.str(line);
		iss.clear();
		btc.evaluateInput(iss);
	}

	return(0);
}
