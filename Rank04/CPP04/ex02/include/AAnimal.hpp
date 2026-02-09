/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 20:01:16 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/02/09 20:18:29 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAnimal_HPP
# define AAnimal_HPP

# include <iostream>

class AAnimal
{
	public:
		AAnimal();
		AAnimal(const AAnimal &other);
		virtual	~AAnimal();
		AAnimal	&operator =(const AAnimal &other);

		std::string		getType(void) const;
		virtual void	makeSound(void) const = 0;

	protected:
		std::string	type;
	};

#endif
