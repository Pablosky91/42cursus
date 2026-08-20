/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 20:13:53 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/07/27 20:17:52 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// DEFAULT CONSTRUCTOR

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(): std::stack<T, Container>()
{
}

// COPY CONSTRUCTOR

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack &other): std::stack<T, Container>(other)
{
}

// DESTRUCTOR

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack()
{
}

// COPY ASSIGNMENT OPERATOR

template <typename T, typename Container>
MutantStack<T, Container>	&MutantStack<T , Container>::operator =(const MutantStack &other)
{
	if (this != &other)
		std::stack<T, Container>::operator =(other);
	return (*this);
}

//PUBLIC MEMBER FUNCTIONS

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator	MutantStack<T, Container>::begin()
{
	return (this->c.begin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator	MutantStack<T, Container>::end()
{
	return (this->c.end());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator	MutantStack<T, Container>::begin() const
{
	return (this->c.begin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator	MutantStack<T, Container>::end() const
{
	return (this->c.end());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator	MutantStack<T, Container>::rbegin()
{
	return (this->c.rbegin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator	MutantStack<T, Container>::rend()
{
	return (this->c.rend());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator	MutantStack<T, Container>::rbegin() const
{
	return (this->c.rbegin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator	MutantStack<T, Container>::rend() const
{
	return (this->c.rend());
}
