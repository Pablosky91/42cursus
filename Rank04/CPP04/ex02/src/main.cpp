/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:59:51 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/02/09 20:21:18 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int	main(void)
{
	AAnimal		*cat = new Cat;
	std::cout << cat->getType() << ": ";
	cat->makeSound();
	delete cat;

	std::cout << std::endl;

	AAnimal		*dog = new Dog;
	std::cout << dog->getType() << ": ";
	dog->makeSound();
	delete dog;

	return (0);
}
