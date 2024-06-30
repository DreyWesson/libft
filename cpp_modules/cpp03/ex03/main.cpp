/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:08:38 by doduwole          #+#    #+#             */
/*   Updated: 2023/12/02 14:23:38 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void) {
    // // Test ScavClap parameterized constructor
    // // ScavTrap trap("Bumble bee");
    // // trap.print_data();
    // // Test ScavClap default constructor
    // DiamondTrap trap1;
    // trap1.attack("Spiderman");
    // trap1.attack("anon");
    // trap1.takeDamage(5);
    // trap1.takeDamage(5);
    // trap1.takeDamage(5);
    // trap1.beRepaired(1);
    // trap1.takeDamage(86);
    DiamondTrap flip( "Batman" );
    DiamondTrap flip2( "Spider" );
    DiamondTrap flip3("Anon");

    flip.whoAmI();
    flip2.whoAmI();
    flip3.whoAmI();
    flip.attack("wind");
    flip.highFivesGuys();
    flip.guardGate();
    return (0);
}
