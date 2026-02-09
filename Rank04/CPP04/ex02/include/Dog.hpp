/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:59:26 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/02/09 20:04:17 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog: public AAnimal
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
