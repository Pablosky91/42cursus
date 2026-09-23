/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 19:41:49 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/09/23 21:50:59 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <deque>
#include <vector>

//DEFAULT CONSTRUCTOR

PmergeMe::PmergeMe()
{
}

//COPY CONSTRUCTOR

PmergeMe::PmergeMe(const PmergeMe& other)
{
	*this = other;
}

PmergeMe::PmergeMe(int *seq, int size)
{
	_seq = seq;
	_size = size;
}

//DESTRUCTOR

PmergeMe::~PmergeMe()
{
}

//COPY ASSIGNMENT OPERATOR

PmergeMe	&PmergeMe::operator =(const PmergeMe &other)
{
	if (this != &other)
	{
		_seq = other._seq;
		_size = other._size;
		_seq_deque = other._seq_deque;
		_seq_vector = other._seq_vector;
	}
	return (*this);
}

//PUBLIC MEMBER FUNCTIONS

std::deque<int>	PmergeMe::getSeqDeque() const
{
	return (_seq_deque);
}

std::vector<int>	PmergeMe::getSeqVector() const
{
	return (_seq_vector);
}

void	PmergeMe::sortDeque()
{
	_seq_deque = std::deque<int>(_seq, _seq + _size);
	mergeInsert(_seq_deque);
}

void	PmergeMe::sortVector()
{
	_seq_vector = std::vector<int>(_seq, _seq + _size);
	mergeInsert(_seq_vector);
}

//PRIVATE MEMBER FUNCTION

int	*PmergeMe::insertionOrder(int size)
{
	int	*series = new int[size];
	int	index = 0;
	int	min = 0;

	for (int j = 0; index < size; j++)
	{
		int	max = ((1 << (j + 2)) - (j % 2 ? -1 : 1)) / 3;
		max = size < max ? size : max;
		for (int i = max; i > min; i--)
			series[index++] = i - 1;
		min = max;
	}
	return (series);
}
