/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 13:52:34 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/02/08 22:35:43 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
	public:
		Dog();
		Dog(const Dog &other);
		~Dog();
		Dog	&operator =(const Dog &other);

		void	makeSound(void) const;
		Brain	*getBrain(void) const;
		void	setBrain(const Brain &brain);

	private:
		Brain	*brain;
	};

#endif
