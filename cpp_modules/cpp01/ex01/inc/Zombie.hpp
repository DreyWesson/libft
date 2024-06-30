/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:09:12 by doduwole          #+#    #+#             */
/*   Updated: 2023/11/17 14:53:56 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <iomanip>

class Zombie {

public:
    Zombie(void);

    ~Zombie(void);

    void announce(void);

    Zombie(std::string name);

private:
    std::string _name;
};

Zombie *zombieHorde(int N, std::string name);

#endif