/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:34:58 by doduwole          #+#    #+#             */
/*   Updated: 2023/11/17 20:44:55 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

Zombie *zombieHorde(int N, std::string name) {
    Zombie *zombies = new Zombie[N];
    for (int i = 0; i < N; ++i) {
        new(&zombies[i]) Zombie(name);
    }
    return (zombies);
}