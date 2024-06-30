/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:17:30 by doduwole          #+#    #+#             */
/*   Updated: 2023/11/14 22:17:26 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {
    std::cout << "Zombie constructor called" << std::endl;
    return;
}

Zombie::~Zombie(void) {
    std::cout << this->_name << " zombie destroyed" << std::endl;
    return;
}

void Zombie::announce(void) {
    std::cout << _name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
    return;
}
