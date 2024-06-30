/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduwoledare <oduwoledare@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 00:45:26 by doduwole          #+#    #+#             */
/*   Updated: 2023/12/09 13:37:40 by oduwoledare      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("")
{
    // std::cout << "\033[2;37m""\033[3m" "AMATERIA constructor called\n" "\033[0m";
}

AMateria::~AMateria()
{
    // std::cout << "\033[2;37m""\033[3m" "AMATERIA destructor called\n" "\033[0m";
}

AMateria::AMateria(std::string const & type) : _type(type) {
    // std::cout << "\033[2;37m""\033[3m" "AMATERIA parameterized constructor called\n" "\033[0m";

}

AMateria::AMateria(AMateria const & cpy) {
    *this = cpy;
}

AMateria &AMateria::operator=(const AMateria &cpy) {
    if (this != &cpy)
       this-> _type = cpy._type;
    return (*this);
}

std::string const &AMateria::getType() const {
    return (this->_type);
}

// AMateria*   AMateria::clone() const; // do nothing - it's a pure virtual function

void AMateria::use(ICharacter& target) {
    std::cout << "AMateria used on " << target.getName() << " *";
}

