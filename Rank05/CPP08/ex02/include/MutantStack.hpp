/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 20:13:49 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/07/27 20:13:50 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <deque>
# include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack: public std::stack<T, Container>
{
	public:
		MutantStack();
		MutantStack(const MutantStack& other);
		MutantStack	&operator =(const MutantStack& other);
		~MutantStack();

		typedef typename		Container::iterator iterator;
		typedef typename		Container::const_iterator const_iterator;
		typedef typename		Container::reverse_iterator reverse_iterator;
		typedef typename		Container::const_reverse_iterator const_reverse_iterator;

		iterator				begin();
		iterator				end();

		const_iterator			begin() const;
		const_iterator			end() const;

		reverse_iterator		rbegin();
		reverse_iterator		rend();

		const_reverse_iterator	rbegin() const;
		const_reverse_iterator	rend() const;
};

# include "MutantStack.tpp"

#endif
