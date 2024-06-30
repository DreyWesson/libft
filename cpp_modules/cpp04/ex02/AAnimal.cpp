/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:26:21 by doduwole          #+#    #+#             */
/*   Updated: 2023/12/07 00:17:36 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./AAnimal.hpp"

AAnimal::AAnimal() : type("Elephant")
{
    std::cout << "Animal constructor called\n";
}

AAnimal::~AAnimal()
{
    std::cout << "Animal destructor called\n";
}

AAnimal::AAnimal(const AAnimal &cpy) {
    *this = cpy;
}

AAnimal &AAnimal::operator=(const AAnimal &cpy) {
    if (this != &cpy)
        type = cpy.type;
    return (*this);
}

void    AAnimal::makeSound() const {
    std::cout << "Animal sound\n";
}

void AAnimal::setType(std::string _type) {
    type = _type;
}

std::string AAnimal::getType(void) const {
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