/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:08:32 by doduwole          #+#    #+#             */
/*   Updated: 2023/12/02 14:21:25 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hitPoints(10), _energyPoints(10), _attackDamage(0){
    print_welcome("ClapTrap constructor ");
    return;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0){
    print_welcome("ClapTrap parameterized constructor ");
    return ;
}

ClapTrap::~ClapTrap(void) {
    std::cout << "ClapTrap destructor called" << std::endl;
    return;
}

ClapTrap::ClapTrap(const ClapTrap &cpy) {
    *this = cpy;
    std::cout << "ClapTrap copy constructor called" << std::endl;
    return ;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &cpy) {
    if (this != &cpy) {
        this->_name = cpy._name;
        this->_attackDamage = cpy._attackDamage;
        this->_energyPoints = cpy._energyPoints;
        this->_hitPoints = cpy._hitPoints;
    }
    return (*this);
}
void ClapTrap::print_welcome(std::string const_type) {
    std::cout << "#############################################" << std::endl;
    std::cout << "#            Welcome to ClapTrap" << std::endl;
    std::cout << "#  ""\033[32m" << const_type << "Initialising..." "\033[0m"<< std::endl;
    std::cout << "#  Name: ""\033[33m" << _name << "\033[0m"<< std::endl;
    std::cout << "#  HitPoints: ""\033[33m" << _hitPoints << "\033[0m"<< std::endl;
    std::cout << "#  EnergyPoints: ""\033[33m" << _energyPoints << "\033[0m"<< std::endl;
    std::cout << "#  AttackDamage: ""\033[33m" << _attackDamage <<"\033[0m"<< std::endl;
    std::cout << "#############################################" << std::endl;
}

void ClapTrap::print_data() {
    std::cout << "Name: ""\033[33m" << _name << "\033[0m"<< std::endl;
    std::cout << "HitPoints: ""\033[33m" << _hitPoints << "\033[0m"<< std::endl;
    std::cout << "EnergyPoints: ""\033[33m" << _energyPoints << "\033[0m"<< std::endl;
    std::cout << "AttackDamage: ""\033[33m" << _attackDamage << "\033[0m"<< std::endl <<std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (_hitPoints <= 0 || _energyPoints <= 0)
    {
        std::cout << target << ", you have no energy or hit points";
        return ;
    }
    _energyPoints--;
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    print_data();
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints <= amount)
    {
        _hitPoints = 0;
        print_data();
        std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
        return ;
    }
    _hitPoints -= amount;
    std::cout << "ClapTrap: Amount of damage done to " << _name << " is " << amount << "!" << std::endl;
    print_data();
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_hitPoints <= 0 || _energyPoints <= 0)
    {
        std::cout << _name << ", you have no energy or hit points" << std::endl;
        return ;
    }
    this->_hitPoints += amount;
    _energyPoints--;
    std::cout << "ClapTrap " << _name << " is repaired by " << amount << " points!" << std::endl;
    std::cout << _energyPoints << " energy point(s) left" << std::endl;
    print_data();
}
