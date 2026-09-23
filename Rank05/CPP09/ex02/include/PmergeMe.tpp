/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 20:25:43 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/09/23 20:58:32 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>

template <typename Container>
void	PmergeMe::mergeInsert(Container &sequence)
{
	Container	main(sequence.begin(), sequence.begin() + sequence.size() / 2);
	Container	pend(sequence.begin() + sequence.size() / 2, sequence.begin() + sequence.size());
	Container	main_copy;
	
	comparePairs(main, pend);
	main_copy = main;

	if (main.size() > 1)
	{
		mergeInsert(main);
		reattachPend(main, main_copy, pend);
	}
	mergePendToMain(main, main_copy, pend);
	sequence = main;
}

template <typename Container>
void	PmergeMe::comparePairs(Container &main, Container &pend)
{
	typename Container::iterator	it_main = main.begin();
	typename Container::iterator	it_pend = pend.begin();

	for (; it_main != main.end(); it_main++, it_pend++)
		if (*it_pend > *it_main)
			std::swap(*it_main, *it_pend);
}

template <typename Container>
void	PmergeMe::reattachPend(const Container &main, Container &main_copy, Container &pend)
{
	Container	pend_copy(pend);

	for (size_t i = 0; i < main.size(); i++)
	{
		for (size_t j = 0; j < main_copy.size(); j++)
		{
			if (main[i] == main_copy[j])
			{
				pend[i] = pend_copy[j];
				main_copy.erase(main_copy.begin() + j);
				pend_copy.erase(pend_copy.begin() + j);
				break ;
			}
		}
	}
	main_copy = main;
}

template <typename Container>
void	PmergeMe::mergePendToMain(Container &main, const Container &main_copy, const Container &pend)
{
	int	*order = insertionOrder(pend.size());

	for (size_t i = 0; i < pend.size(); i++)
	{
		int pos = main.size();
		if (static_cast<size_t>(order[i]) < main_copy.size())
		{
			pos = order[i];
			while (main[pos] != main_copy[order[i]])
				pos++;
		}
		insertBinary(main, pend[order[i]], pos);
	}
	delete[] order;
}

template <typename Container>
void	PmergeMe::insertBinary(Container &main, int value, int high)
{
	int	low = 0;
	int	mid;

	while (low < high)
	{
		mid = (low + high) / 2;
		if (value < main[mid])
			high = mid;
		else if (value > main[mid])
			low = mid + 1;
		else
		{
			main.insert(main.begin() + mid, value);
			return ;
		}
	}
	main.insert(main.begin() + low, value);
}
