/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:56:02 by doduwole          #+#    #+#             */
/*   Updated: 2023/12/07 00:29:55 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"


int main()
{
    // Dog animal; // this works
    // AAnimal animal; // this doesn't
    // Below is how to call AAnimal class.
    // Thanks to polymorphism 
    const AAnimal* j = new Dog(); 
    const AAnimal* i = new Cat();

    j->makeSound();
    i->makeSound();
    delete j;//should not create a leak
    delete i;

    return 0;
}