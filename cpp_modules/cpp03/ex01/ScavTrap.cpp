/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:04:04 by doduwole          #+#    #+#             */
/*   Updated: 2023/12/02 14:19:03 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    print_welcome("ScavTrap default constructor ");
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    print_welcome("ScavTrap parameterized constructor ");
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap: " << (_name.empty() ? "n/a" : _name) <<  " destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &cpy){
    *this = cpy;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &cpy) {
    if (this != &cpy) {
        this->_name = cpy._name;
        this->_attackDamage = cpy._attackDamage;
        this->_energyPoints = cpy._energyPoints;
        this->_hitPoints = cpy._hitPoints;
    }
    return (*this);
}

void ScavTrap::attack(const std::string& target) {
    if (_hitPoints <= 0 || _energyPoints <= 0)
    {
        std::cout << target << ", you have no energy or hit points";
        return ;
    }
    _energyPoints--;
    std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    print_data();
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode\n";
}
