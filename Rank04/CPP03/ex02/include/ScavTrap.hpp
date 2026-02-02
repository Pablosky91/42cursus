/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:25:56 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/02/02 11:25:57 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const ScavTrap& other);
		ScavTrap(std::string name);
		~ScavTrap();
		ScavTrap	&operator =(const ScavTrap &other);

		void	attack(const std::string &target);
		void	guardGate();

	private:

	};

#endif
