/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:10:57 by doduwole          #+#    #+#             */
/*   Updated: 2023/11/18 18:00:39 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) {}

Weapon::Weapon(std::string type) {
    Weapon::setType(type);
}

Weapon::~Weapon(void) {}

const std::string Weapon::getType(void) {
    return ((const std::string) this->_type);
}

void Weapon::setType(std::string type) {
    this->_type = type;
}
