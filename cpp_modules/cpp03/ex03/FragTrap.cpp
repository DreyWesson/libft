/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:04:04 by doduwole          #+#    #+#             */
/*   Updated: 2023/12/02 13:30:13 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap default constructor called\n";
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    std::cout << "FragTrap parameterized constructor called\n";
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap: " << (_name.empty() ? "n/a" : _name) <<  " destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &cpy){
    *this = cpy;
}

FragTrap &FragTrap::operator=(const FragTrap &cpy) {
    if (this != &cpy) {
        this->_name = cpy._name;
        this->_attackDamage = cpy._attackDamage;
        this->_energyPoints = cpy._energyPoints;
        this->_hitPoints = cpy._hitPoints;
    }
    return (*this);
}

void FragTrap::highFivesGuys(void) {
    std::cout << _name << (_name.empty() ? "" : ": ") << "\033[32m""High five guys!!!\n""\033[0m";
}
