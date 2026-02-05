/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:52:56 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/02/02 23:06:40 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: public virtual ClapTrap
{
	public:
		FragTrap();
		FragTrap(const FragTrap& other);
		FragTrap(std::string name);
		~FragTrap();
		FragTrap	&operator =(const FragTrap &other);

		void	highFivesGuys(void);

	private:

	};

#endif
