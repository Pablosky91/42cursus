/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:09:57 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/02/05 20:10:24 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include <iostream>

class DiamondTrap: public ScavTrap, public FragTrap
{
	public:
		DiamondTrap();
		DiamondTrap(const DiamondTrap &other);
		DiamondTrap(std::string name);
		~DiamondTrap();
		DiamondTrap	&operator =(const DiamondTrap &other);

		void	whoAmI(void);

	private:
		std::string	_name;

	};

#endif
