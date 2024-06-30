/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:42:58 by doduwole          #+#    #+#             */
/*   Updated: 2023/12/07 00:16:18 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : AAnimal()
{
    std::cout << "Dog constructor called\n";
    type = "Dog";
    try {
        this->brain = new Brain();
    }
    catch (const std::bad_alloc& e) {
        std::cout << "Memory Allocation is failed\n";
    }
}

Dog::~Dog()
{
    std::cout << "Dog destructor called\n";
    delete brain;
}

Dog::Dog(const Dog &cpy) {
    *this = cpy;
}

Dog &Dog::operator=(const Dog &cpy) {
    std::cout << "Dog assignment called\n";
    if (this != &cpy)
    {
        this->type = cpy.type;
        this->brain = new Brain( *cpy.brain );
    }
    return (*this);
}

void Dog::makeSound(void) const {
    std::cout << "Bark!!!\n";
}