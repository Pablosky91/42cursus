/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 19:04:46 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/08/01 22:25:18 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "Date.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

//DEFAULT CONSTRUCTOR

BitcoinExchange::BitcoinExchange()
{
}

//COPY CONSTRUCTOR

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

//DESTRUCTOR

BitcoinExchange::~BitcoinExchange()
{
}

//COPY ASSIGNMENT OPERATOR

BitcoinExchange	&BitcoinExchange::operator =(const BitcoinExchange &other)
{
	if (this != &other)
		_prices = other._prices;
	return (*this);
}

//PUBLIC MEMBER FUNCTIONS


void	BitcoinExchange::loadDatabase(std::ifstream &ifs)
{
	std::string		aux;
	char			delimiter;
	Date			date;
	float			price;

	std::getline(ifs, aux, '\n');

	while (ifs >> date >> delimiter >> price)
		_prices.insert(std::pair<Date, float>(date, price));

	if (_prices.empty())
		throw std::runtime_error("No exchange rates provided");
}

void	BitcoinExchange::evaluateInput(std::istringstream &iss) const
{
	Date									date;
	char									delimiter;
	float									value;
	std::map<Date, float>::const_iterator	it;

	try
	{
		if (!(iss >> date >> delimiter >> value))
			throw std::runtime_error("Lines must use the format: \"date | value\"");
		if (delimiter != '|')
			throw std::runtime_error("Lines must use the format: \"date | value\"");
		if (value < 0)
			throw std::runtime_error("Value must not be negative");
		if (value > 1000)
			throw std::runtime_error("Value must not exceed 1000");

		it = _prices.lower_bound(date);
		if (it == _prices.begin())
			std::cout << "Earliest available price data is " << it->first << std::endl;
		else
		{
			if (it->first != date)
				it--;
			std::cout << std::fixed << std::setprecision(2) << date << " => " << it->second << " = " << it->second * value << std::endl;
		}
	}
	catch(const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
}
