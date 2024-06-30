/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:17:30 by doduwole          #+#    #+#             */
/*   Updated: 2023/11/17 20:47:25 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

Zombie::Zombie(void) {
    std::cout << "Constructor called" << std::endl;
}

Zombie::Zombie(std::string name) : _name(name) {}

Zombie::~Zombie(void) {
    std::cout << this->_name << " zombie destroyed" << std::endl;
}

void Zombie::announce(void) {
    std::cout << _name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
    return;
}
