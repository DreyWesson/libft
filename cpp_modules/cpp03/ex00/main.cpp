/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:08:38 by doduwole          #+#    #+#             */
/*   Updated: 2023/12/02 10:36:17 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
    ClapTrap trap("Bumble Bee");
    trap.attack("spider");
    trap.attack("anon");
    trap.takeDamage(5);
    trap.takeDamage(5);
    trap.takeDamage(5);
    trap.beRepaired(1);
    return (0);
}
