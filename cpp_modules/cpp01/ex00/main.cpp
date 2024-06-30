/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:06:17 by doduwole          #+#    #+#             */
/*   Updated: 2023/11/17 13:36:57 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/Zombie.hpp"

int main(void) {
    Zombie zombie("Mortis Max");
    zombie.announce();

    Zombie *heap_zombie = newZombie("Rotten Ronin");
    heap_zombie->announce();

    randomChump("Gory Gary");
    delete heap_zombie;
    return (0);
}