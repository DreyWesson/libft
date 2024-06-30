/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 11:59:54 by doduwole          #+#    #+#             */
/*   Updated: 2023/12/02 14:20:19 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap()
{
    FragTrap::_hitPoints = 100;
    ScavTrap::_energyPoints = 100;
    FragTrap::_attackDamage = 30;
    print_welcome("DiamondTrap default constructor ");
}

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap( name ), ScavTrap( name ), FragTrap( name )
{
    _name = name;
    ClapTrap::_name = name + "_clap_name";
    FragTrap::_hitPoints = 100;
    FragTrap::_attackDamage = 30;
    ScavTrap::_energyPoints = 100;
    print_welcome("DiamondTrap parameterized constructor ");
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap: " << (_name.empty() ? "n/a" : _name) <<  " destructor called" << std::endl;
}

void DiamondTrap::print_welcome(std::string const_type) {
    std::cout << "#############################################" << std::endl;
    std::cout << "#            Welcome to DiamondTrap" << std::endl;
    std::cout << "#  ""\033[32m"<< const_type <<"Initialising..." "\033[0m"<< std::endl;
    std::cout << "#  Name: ""\033[33m" << _name << "\033[0m"<< std::endl;
    std::cout << "#  HitPoints: ""\033[33m" << FragTrap::_hitPoints << "\033[0m"<< std::endl;
    std::cout << "#  EnergyPoints: ""\033[33m" << ScavTrap::_energyPoints << "\033[0m"<< std::endl;
    std::cout << "#  AttackDamage: ""\033[33m" << FragTrap::_attackDamage <<"\033[0m"<< std::endl;
    std::cout << "#############################################" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &cpy){
    *this = cpy;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &cpy) {
    if (this != &cpy) {
        this->_name = cpy._name;
        this->FragTrap::_attackDamage = cpy.FragTrap::_attackDamage;
        this->ScavTrap::_energyPoints = cpy.ScavTrap::_energyPoints;
        this->FragTrap::_hitPoints = cpy.FragTrap::_hitPoints;
    }
    return (*this);
}

void    DiamondTrap::whoAmI( void ) {
    std::cout << "DiamondTrap name: " << this->_name << ", ClapTrap name: " << ClapTrap::_name << std::endl;
}
