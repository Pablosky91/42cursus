/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 13:15:07 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/07/25 13:27:37 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <stdexcept>
# include <vector>

class Span
{
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &other);
		~Span();
		Span						&operator =(const Span &other);

		void						addNumber(int value);
		template <typename It> void	addRange(It begin, It end);

		unsigned int				shortestSpan();
		unsigned int				longestSpan();

	private:
		unsigned int		_N; //maximum capacity
		std::vector<int>	_numbers;
};

template <typename It>
void	Span::addRange(It begin, It end)
{
	std::vector<int>	incoming(begin, end);
	std::vector<int>	merged;

	if (_numbers.size() + incoming.size() > _N)
		throw std::exception();
	std::sort(incoming.begin(), incoming.end());
	std::merge(_numbers.begin(), _numbers.end(), incoming.begin(), incoming.end(), std::back_inserter(merged));
	_numbers.swap(merged);
}

#endif
