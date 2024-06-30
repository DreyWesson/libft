/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:31:03 by doduwole          #+#    #+#             */
/*   Updated: 2023/12/06 13:41:04 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Cat constructor called\n";
    type = "Cat";
}

Cat::~Cat()
{
    std::cout << "Cat destructor called\n";
}

Cat::Cat(const Cat &cpy) {
    *this = cpy;
}

Cat &Cat::operator=(const Cat &cpy) {
    if (this != &cpy)
        type = cpy.type;
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
