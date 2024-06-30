/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:06:17 by doduwole          #+#    #+#             */
/*   Updated: 2023/11/17 19:42:56 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/Zombie.hpp"

int main(void) {
    int N = 10;
    Zombie *horde = zombieHorde(N, "Gory Gary");
    for (int i = 0; i < N; ++i) {
        std::cout << std::setw(2) << std::setfill('0') << i + 1 << ". ";
        horde[i].announce();
    }
    delete[] horde;
    return (0);
}
 