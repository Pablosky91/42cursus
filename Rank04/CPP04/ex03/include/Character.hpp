/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 10:30:20 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/02/10 13:53:03 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <iostream>

# define INV_SIZE 4

class Character: public ICharacter
{
	public:
		Character();
		Character(const Character &other);
		Character(std::string name);
		~Character();
		Character	&operator =(const Character &other);

		std::string const	&getName(void) const;
		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter &target);

		AMateria			*getSlot(int idx) const;
		void				setName(std::string const name);

	private:
		std::string	_name;
		AMateria	*_inventory[INV_SIZE];
	};

#endif
