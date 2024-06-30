/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:42:58 by doduwole          #+#    #+#             */
/*   Updated: 2023/12/06 13:41:18 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Dog constructor called\n";
    type = "Dog";
}

Dog::~Dog()
{
    std::cout << "Dog destructor called\n";
}

Dog::Dog(const Dog &cpy) {
    *this = cpy;
}

Dog &Dog::operator=(const Dog &cpy) {
    if (this != &cpy)
        type = cpy.type;
    return (*this);
}

void Dog::makeSound(void) const {
    std::cout << "Bark!!!\n";
}