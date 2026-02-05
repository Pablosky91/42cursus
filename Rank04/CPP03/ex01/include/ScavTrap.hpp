/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 22:19:56 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/02/05 20:10:55 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class ScavTrap: public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const ScavTrap &other);
		ScavTrap(std::string name);
		~ScavTrap();
		ScavTrap	&operator =(const ScavTrap &other);

		void	attack(const std::string &target);
		void	guardGate(void);
	};

#endif
