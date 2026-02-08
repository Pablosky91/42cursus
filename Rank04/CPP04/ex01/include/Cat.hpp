/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 13:52:29 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/02/08 22:56:54 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
	public:
		Cat();
		Cat(const Cat &other);
		~Cat();
		Cat	&operator =(const Cat &other);

		void	makeSound(void) const;
		Brain	*getBrain(void) const;
		void	setBrain(const Brain &brain);

	private:
		Brain	*brain;
	};

#endif
