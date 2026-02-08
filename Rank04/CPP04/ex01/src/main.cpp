/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 13:53:05 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/02/08 23:06:42 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int	main(void)
{
	Brain	*brain = new Brain;
	brain->newIdea("1");
	brain->setIdea(2, "2");
	brain->setIdea(12, "3");
	brain->newIdea("4");
	brain->newIdea("5");
	brain->setIdea(123, "5");
	brain->listIdeas();

	Dog	*dog = new Dog;
	dog->getBrain()->newIdea("old");
	dog->getBrain()->listIdeas();

	dog->setBrain(*brain);
	delete brain;

	dog->getBrain()->newIdea("dog");
	dog->getBrain()->listIdeas();
	
	Dog	*other = new Dog(*dog);
	delete dog;

	other->getBrain()->newIdea("other");
	other->getBrain()->listIdeas();
	delete other;

	Animal	*animals[6];

	for (int i = 0; i < 6; i++)
	{
		if (i < 3)
			animals[i] = new Cat;
		else
			animals[i] = new Dog;
	}

	for (int i = 0; i < 6; i++)
		delete animals[i];

	return (0);
}
