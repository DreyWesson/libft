/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:31:03 by doduwole          #+#    #+#             */
/*   Updated: 2023/12/07 00:19:19 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : AAnimal()
{
    std::cout << "Cat constructor called\n";
    type = "Cat";
    try {
        this->brain = new Brain();
    }
    catch (const std::bad_alloc& e) {
        std::cout << "Memory Allocation is failed\n";
    }
}

Cat::~Cat()
{
    std::cout << "Cat destructor called\n";
    delete this->brain;
}

Cat::Cat(const Cat &cpy) {
    *this = cpy;
}

Cat &Cat::operator=(const Cat &cpy) {
    std::cout << "Cat assignment called\n";
    if (this != &cpy)
    {
        this->type = cpy.type;
        this->brain = new Brain( *cpy.brain );
    }
    return (*this);
}

void Cat::makeSound(void) const {
    std::cout << "Meow!!!\n";
}

/**
 * WrongCat
*/
WrongCat::WrongCat() : WrongAnimal()
{
    std::cout << "WrongCat constructor called\n";
    type = "Cat";
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called\n";
}

WrongCat::WrongCat(const WrongCat &cpy) {
    *this = cpy;
}

WrongCat &WrongCat::operator=(const WrongCat &cpy) {
    (void) cpy;
    return (*this);
}

void WrongCat::makeSound(void) const {
    std::cout << "WrongCat making meow sound!!!\n";
}
