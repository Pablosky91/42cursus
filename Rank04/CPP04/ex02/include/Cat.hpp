/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:59:21 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/02/09 20:04:17 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat: public AAnimal
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
