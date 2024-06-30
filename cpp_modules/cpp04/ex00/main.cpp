/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:56:02 by doduwole          #+#    #+#             */
/*   Updated: 2023/12/06 23:40:28 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void structors_chaining(void) {
    Animal animal0;
    Animal* animal = new Cat;
    Animal* animal2 = new Dog;

    animal->makeSound();
    animal2->makeSound();
    delete animal;
    delete animal2;
}
void wrong_test(void) {
    const WrongAnimal* meta = new WrongAnimal();
    const WrongAnimal* i = new WrongCat();
    WrongCat wrong;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); 
    meta->makeSound();
    wrong.makeSound();
    delete meta;
    delete i;
}

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    delete i;
    delete j;
    delete meta;
    // structors_chaining();
    // wrong_test();
    return 0;
}