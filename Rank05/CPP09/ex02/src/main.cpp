/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 21:33:22 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/09/23 21:45:02 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "Stopwatch.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>

void	validateInput(int argc, char **argv, int *seq, std::string &before_text);
template <typename Container> std::string	getAfterText(Container c);

int	main(int argc, char **argv)
{
	int			*seq = new int[argc - 1];
	PmergeMe	sorter(seq, argc - 1);
	std::string	before_text;
	Stopwatch	stopwatch_deque, stopwatch_vector;

	try
	{
		validateInput(argc, argv, seq, before_text);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		delete[] seq;
		return (0);
	}

	stopwatch_deque.start();
	sorter.sortDeque();
	stopwatch_deque.stop();
	
	stopwatch_vector.start();
	sorter.sortVector();
	stopwatch_vector.stop();

	std::cout << std::fixed << std::setprecision(3);
	std::cout << before_text;
	std::cout << getAfterText(sorter.getSeqDeque());
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque: " << stopwatch_deque.get_time() << " ms" << std::endl;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector: " << stopwatch_vector.get_time() << " ms" << std::endl;

	delete[] seq;
	return (0);
}

void	validateInput(int argc, char **argv, int *seq, std::string &before_text)
{
	std::istringstream	iss;
	std::ostringstream	oss;

	if (argc == 1)
		throw std::runtime_error("Pass a positive integer sequence as argumets");
	oss << "Before:";
	for (int i = 1; i < argc; i++)
	{
		iss.str(argv[i]);
		if (!(iss >> seq[i - 1]) || !iss.eof() || seq[i - 1] <= 0)
			throw std::runtime_error("Arguments must be positive integers");
		oss << " " << argv[i];
		iss.clear();
	}
	oss << std::endl;
	before_text = oss.str();
}

template <typename Container>
std::string	getAfterText(Container c)
{
	std::ostringstream	oss;
	
	oss << "After: ";
	for (typename Container::iterator it = c.begin(); it != c.end(); it++)
		oss << " " << *it;
	oss << std::endl;
	return (oss.str());
}
