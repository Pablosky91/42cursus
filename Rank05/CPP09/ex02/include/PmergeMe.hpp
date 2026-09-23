/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 19:41:44 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/09/23 21:53:50 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <deque>
# include <vector>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe(int *seq, int size);
		~PmergeMe();
		PmergeMe	&operator =(const PmergeMe &other);

		std::deque<int>		getSeqDeque() const;
		std::vector<int>	getSeqVector() const;
		
		void	sortDeque();
		void	sortVector();

	private:
		int	*_seq;
		int	_size;

		std::deque<int>		_seq_deque;
		std::vector<int>	_seq_vector;

		int	*insertionOrder(int size);

		template <typename Container> void	mergeInsert(Container &main);
		template <typename Container> void	comparePairs(Container &main, Container &pend);
		template <typename Container> void	reattachPend(const Container &main, Container &main_copy, Container &pend);
		template <typename Container> void	mergePendToMain(Container &main, const Container &main_copy, const Container &pend);
		template <typename Container> void	insertBinary(Container &main, int value, int high);
};

# include "PmergeMe.tpp"

#endif
