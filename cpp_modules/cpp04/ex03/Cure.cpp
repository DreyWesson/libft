/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:03:30 by doduwole          #+#    #+#             */
/*   Updated: 2023/12/09 19:05:41 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    // std::cout << "\033[2;37m""\033[3m" "CURE constructor called\n" "\033[0m";
}

Cure::~Cure()
{
    // std::cout << "\033[2;37m""\033[3m" "CURE deconstructor called\n" "\033[0m";
}

Cure::Cure(const Cure &cpy) : AMateria("cure") {
    *this = cpy;
}

Cure &Cure::operator=(const Cure &cpy) {
    if (this != &cpy)
        this->_type = cpy._type;
    return (*this);
}

AMateria* Cure::clone() const {
    return (new Cure(*this));
}

void        Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *\n";
}
