/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 10:14:50 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/02/10 11:40:27 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <iostream>

class Ice: public AMateria
{
	public:
		Ice();
		Ice(const Ice &other);
		~Ice();
		Ice	&operator =(const Ice &other);

		Ice		*clone(void) const;
		void	use(ICharacter &target);
	};

#endif
