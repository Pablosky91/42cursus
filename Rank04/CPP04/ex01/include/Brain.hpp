/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 21:07:05 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/02/08 21:25:41 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	public:
		Brain();
		Brain(const Brain &other);
		~Brain();
		Brain	&operator =(const Brain &other);

		std::string	getIdea(int n) const;
		void		setIdea(int n, std::string idea);
		bool		newIdea(std::string idea);
		void		listIdeas(void) const;

	private:
		std::string	ideas[100];
	};

#endif
