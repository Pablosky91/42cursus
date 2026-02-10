/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 10:14:53 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/02/10 11:40:22 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <iostream>

class Cure: public AMateria
{
	public:
		Cure();
		Cure(const Cure &other);
		~Cure();
		Cure	&operator =(const Cure &other);

		Cure	*clone(void) const;
		void	use(ICharacter &target);
	private:

	};

#endif
