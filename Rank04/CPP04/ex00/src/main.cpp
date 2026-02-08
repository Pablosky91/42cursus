/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 22:32:31 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/02/08 11:16:00 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	std::cout << std::endl;
	Animal		*animal = new Animal;
	std::cout << animal->getType() << ": ";
	animal->makeSound();
	delete animal;

	std::cout << std::endl;
	Animal		*cat = new Cat;
	std::cout << cat->getType() << ": ";
	cat->makeSound();
	delete cat;

	std::cout << std::endl;
	Animal		*dog = new Dog;
	std::cout << dog->getType() << ": ";
	dog->makeSound();
	delete dog;

	std::cout << std::endl;
	WrongAnimal	*wanimal = new WrongAnimal;
	std::cout << wanimal->getType() << ": ";
	wanimal->makeSound();
	delete wanimal;

	std::cout << std::endl;
	WrongAnimal	*wcat = new WrongCat;
	std::cout << wcat->getType() << ": ";
	wcat->makeSound();
	delete wcat;

	return (0);
}
