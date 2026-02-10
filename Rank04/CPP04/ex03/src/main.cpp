/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:02:36 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/02/10 14:29:38 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
# include <iostream>

#define RESET	"\033[0m"
#define MAGENTA	"\033[35m"

int	main(void)
{
	std::cout << MAGENTA << "Constructors" << std::endl << RESET;
	Character		*chara = new Character("Chara");
	MateriaSource	*src1 = new MateriaSource;
	AMateria		*ice = new Ice;
	AMateria		*cure = new Cure;

	std::cout << MAGENTA << "MateriaSource 1" << std::endl << RESET;
	src1->createMateria("ice");
	src1->learnMateria(ice);
	src1->learnMateria(ice);
	src1->learnMateria(ice);
	AMateria	*copyIce = src1->createMateria("ice");
	copyIce->use(*chara);

	std::cout << MAGENTA << "Copying MateriaSource" << std::endl << RESET;
	MateriaSource	*src2 = new MateriaSource(*src1);

	std::cout << MAGENTA << "MateriaSource 1" << std::endl << RESET;
	src1->learnMateria(ice);
	src1->learnMateria(cure);
	src1->createMateria("cure");

	std::cout << MAGENTA << "MateriaSource 2" << std::endl << RESET;
	src2->learnMateria(cure);
	AMateria	*copyCure = src2->createMateria("cure");
	copyCure->use(*chara);
	src2->createMateria("fire");

	std::cout << MAGENTA << "Character 1" << std::endl << RESET;
	chara->unequip(0);
	chara->use(0, *chara);
	chara->equip(src1->createMateria("ice"));
	chara->equip(src2->createMateria("cure"));

	std::cout << MAGENTA << "Copying Character" << std::endl << RESET;
	Character	*frisk = new Character(*chara);
	frisk->setName("Frisk");
	
	std::cout << MAGENTA << "Character 2" << std::endl << RESET;
	frisk->equip(src1->createMateria("ice"));
	AMateria	*floor = frisk->getSlot(2);
	frisk->use(2, *chara);
	frisk->unequip(2);
	frisk->equip(src2->createMateria("cure"));
	frisk->equip(src2->createMateria("cure"));
	frisk->equip(cure);

	std::cout << MAGENTA << "Destructors" << std::endl << RESET;
	delete ice;
	delete cure;
	delete copyIce;
	delete copyCure;
	delete src1;
	delete src2;
	delete chara;
	delete frisk;
	delete floor;

	return (0);
}