/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:26:21 by doduwole          #+#    #+#             */
/*   Updated: 2023/12/07 00:05:20 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Animal.hpp"

Animal::Animal() : type("Elephant")
{
    std::cout << "Animal constructor called\n";
}

Animal::~Animal()
{
    std::cout << "Animal destructor called\n";
}

Animal::Animal(const Animal &cpy) {
    *this = cpy;
}

Animal &Animal::operator=(const Animal &cpy) {
    if (this != &cpy)
        type = cpy.type;
    return (*this);
}

void    Animal::makeSound() const {
    std::cout << "Animal sound\n";
}

void Animal::setType(std::string _type) {
    type = _type;
}

std::string Animal::getType(void) const {
    std::cout << "type :" << type << "\n";
    return (type);
}

/**
 * WrongAnimal Starts
*/
WrongAnimal::WrongAnimal() : type("Elephant")
{
    std::cout << "Animal constructor called\n";
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Animal destructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &cpy) {
    *this = cpy;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &cpy) {
    (void) cpy;
    return (*this);
}

void    WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal sound\n";
}

void WrongAnimal::setType(std::string _type) {
    type = _type;
}

std::string WrongAnimal::getType(void) const {
    return (type);
}