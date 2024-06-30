/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:03:34 by doduwole          #+#    #+#             */
/*   Updated: 2023/12/09 19:05:50 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    // std::cout << "\033[2;37m""\033[3m" "ICE constructor called\n" "\033[0m";
}

Ice::~Ice()
{
    // std::cout << "\033[2;37m""\033[3m" "ICE deconstructor called\n" "\033[0m";
}

Ice::Ice(const Ice &cpy) : AMateria("ice") {
    *this = cpy;
}

Ice &Ice::operator=(const Ice &cpy) {
    if (this != &cpy)
        AMateria::operator=(cpy);
    return (*this);
}

AMateria* Ice::clone() const {
    return (new Ice(*this));
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}