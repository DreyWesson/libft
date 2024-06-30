/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:31:47 by doduwole          #+#    #+#             */
/*   Updated: 2023/11/18 17:05:20 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_H
#define HUMAN_A_H

#include <iostream>
#include <iomanip>
#include "Weapon.hpp"

class HumanA {
private:
    Weapon &_weapon;
    std::string _name;

public:
    HumanA();

    HumanA(std::string name, Weapon &weapon);

    ~HumanA();

    void attack(void);
};

#endif