/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:04:04 by doduwole          #+#    #+#             */
/*   Updated: 2023/12/02 14:20:39 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    print_welcome("FragTrap default constructor ");
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    print_welcome("FragTrap parameterized constructor ");
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap: " << (_name.empty() ? "n/a" : _name) <<  " destructor called" << std::endl;
}

void FragTrap::print_welcome(std::string const_type) {
    std::cout << "#############################################" << std::endl;
    std::cout << "#            Welcome to FragTrap" << std::endl;
    std::cout << "#  ""\033[32m"<< const_type <<"Initialising..." "\033[0m"<< std::endl;
    std::cout << "#  Name: ""\033[33m" << _name << "\033[0m"<< std::endl;
    std::cout << "#  HitPoints: ""\033[33m" << _hitPoints << "\033[0m"<< std::endl;
    std::cout << "#  EnergyPoints: ""\033[33m" << _energyPoints << "\033[0m"<< std::endl;
    std::cout << "#  AttackDamage: ""\033[33m" << _attackDamage <<"\033[0m"<< std::endl;
    std::cout << "#############################################" << std::endl;
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

void FragTrap::attack(const std::string& target) {
    if (_hitPoints <= 0 || _energyPoints <= 0)
    {
        std::cout << target << ", you have no energy or hit points";
        return ;
    }
    _energyPoints--;
    std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    print_data();
}

void FragTrap::highFivesGuys(void) {
    std::cout << _name << (_name.empty() ? "" : ": ") << "\033[32m""High five guys!!!\n""\033[0m";
}
