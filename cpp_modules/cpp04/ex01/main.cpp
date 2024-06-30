/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:56:02 by doduwole          #+#    #+#             */
/*   Updated: 2023/12/06 23:59:55 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void other_tests() {
    // Create an Animal with a Brain
    Animal originalAnimal;
    originalAnimal.setType("Animal");

    originalAnimal.getType();
    // Create a new Animal using the copy constructor
    Animal copiedAnimal(originalAnimal);
    copiedAnimal.getType();

    // Create another Animal using assignment operator
    Animal assignedAnimal;
    assignedAnimal = originalAnimal;
    assignedAnimal.getType();

}

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;//should not create a leak
    delete i;

    // const int numAnimals = 10;
    // Animal* animal[numAnimals];

    // for (int i = 0; i < numAnimals; ++i) {
    //     if (i < numAnimals / 2)
    //         animal[i] = new Dog();
    //     else
    //         animal[i] = new Cat();
    // }
    // for ( int i = 0; i < numAnimals; i++ ) {
    //     delete animal[i];
    // }
    // other_tests();

    return 0;
}