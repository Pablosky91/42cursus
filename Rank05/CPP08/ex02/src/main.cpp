/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 20:10:46 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/07/27 20:11:44 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

void	add(int value, MutantStack<int> &mutantStack, MutantStack<int, std::list<int> > &mutantList, std::list<int> &list)
{
	mutantStack.push(value);
	mutantList.push(value);
	list.push_back(value);
}

void	remove(MutantStack<int> &mutantStack, MutantStack<int, std::list<int> > &mutantList, std::list<int> &list)
{
	mutantStack.pop();
	mutantList.pop();
	list.pop_back();
}

void	show_size(const MutantStack<int> &mutantStack, const MutantStack<int, std::list<int> > &mutantList, const std::list<int> &list)
{
	std::cout << "Sizes: ";
	std::cout << mutantStack.size() << ", ";
	std::cout << mutantList.size() << ", ";
	std::cout << list.size() << std::endl;
}

void	show_last(const MutantStack<int> &mutantStack, const MutantStack<int, std::list<int> > &mutantList, const std::list<int> &list)
{
	std::cout << "Last values: ";
	std::cout << mutantStack.top() << ", ";
	std::cout << mutantList.top() << ", ";
	std::cout << list.back() << std::endl;
}

void	show_values(MutantStack<int> &mutantStack, MutantStack<int, std::list<int> > &mutantList, std::list<int> &list)
{
	MutantStack<int>::iterator			it_ms = mutantStack.begin();
	MutantStack<int>::const_iterator	ite_ms = mutantStack.end();

	std::cout << "Mutant stack values: " << std::endl;
	for (; it_ms != ite_ms; it_ms++)
		std::cout << *it_ms << " ";
	std::cout << std::endl;

	MutantStack<int, std::list<int> >::iterator			it_ml = mutantList.begin();
	MutantStack<int, std::list<int> >::const_iterator	ite_ml = mutantList.end();

	std::cout << "Mutant list values: " << std::endl;
	for (; it_ml != ite_ml; it_ml++)
		std::cout << *it_ml << " ";
	std::cout << std::endl;

	std::list<int>::iterator		it_l = list.begin();
	std::list<int>::const_iterator	ite_l = list.end();

	std::cout << "List values: " << std::endl;
	for (; it_l != ite_l; it_l++)
		std::cout << *it_l << " ";
	std::cout << std::endl;
}

void	show_reverse_values(MutantStack<int> &mutantStack, MutantStack<int, std::list<int> > &mutantList, std::list<int> &list)
{
	MutantStack<int>::reverse_iterator			it_ms = mutantStack.rbegin();
	MutantStack<int>::const_reverse_iterator	ite_ms = mutantStack.rend();

	std::cout << "Mutant stack reverse values: " << std::endl;
	for (; it_ms != ite_ms; it_ms++)
		std::cout << *it_ms << " ";
	std::cout << std::endl;

	MutantStack<int, std::list<int> >::reverse_iterator			it_ml = mutantList.rbegin();
	MutantStack<int, std::list<int> >::const_reverse_iterator	ite_ml = mutantList.rend();

	std::cout << "Mutant list reverse values: " << std::endl;
	for (; it_ml != ite_ml; it_ml++)
		std::cout << *it_ml << " ";
	std::cout << std::endl;

	std::list<int>::reverse_iterator		it_l = list.rbegin();
	std::list<int>::const_reverse_iterator	ite_l = list.rend();

	std::cout << "List reverse values: " << std::endl;
	for (; it_l != ite_l; it_l++)
		std::cout << *it_l << " ";
	std::cout << std::endl;
}

int	main(void)
{
	MutantStack<int>					mutantStack;
	MutantStack<int, std::list<int> >	mutantList;
	std::list<int>						list;

	show_size(mutantStack, mutantList, list);

	add(10, mutantStack, mutantList, list);
	show_size(mutantStack, mutantList, list);
	show_last(mutantStack, mutantList, list);

	add(42, mutantStack, mutantList, list);
	show_size(mutantStack, mutantList, list);
	show_last(mutantStack, mutantList, list);

	remove(mutantStack, mutantList, list);
	show_size(mutantStack, mutantList, list);
	show_last(mutantStack, mutantList, list);

	add(20, mutantStack, mutantList, list);
	add(30, mutantStack, mutantList, list);
	add(40, mutantStack, mutantList, list);
	add(50, mutantStack, mutantList, list);

	show_values(mutantStack, mutantList, list);
	show_reverse_values(mutantStack, mutantList, list);

	return (0);
}
