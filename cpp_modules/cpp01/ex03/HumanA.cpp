/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:32:51 by doduwole          #+#    #+#             */
/*   Updated: 2023/11/18 22:26:07 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon), _name(name) {}

HumanA::~HumanA() {
    std::cout << "deconstructor called" << std::endl;
}

void HumanA::attack(void) {
    std::cout << this->_name << " attacks with their " << HumanA::_weapon.getType() << std::endl;
}
