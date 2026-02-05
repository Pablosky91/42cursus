/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:27:34 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/02/05 20:10:46 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class FragTrap: public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const FragTrap &other);
		FragTrap(std::string name);
		~FragTrap();
		FragTrap	&operator =(const FragTrap &other);

		void	highFivesGuys(void);
	};

#endif
