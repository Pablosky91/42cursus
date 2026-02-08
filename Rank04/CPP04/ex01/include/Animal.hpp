/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 13:52:24 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/02/08 13:52:25 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	public:
		Animal();
		Animal(const Animal &other);
		virtual	~Animal();
		Animal	&operator =(const Animal &other);

		std::string		getType(void) const;
		virtual void	makeSound(void) const;

	protected:
		std::string	type;
	};

#endif
