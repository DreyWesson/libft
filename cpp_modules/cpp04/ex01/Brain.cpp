/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 03:28:32 by doduwole          #+#    #+#             */
/*   Updated: 2023/12/06 23:58:17 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called\n";
    for (int i = 0; i < 100; i++)
        ideas[i] = "something";
}

Brain::~Brain()
{
    std::cout << "Brain destructor called\n";
}

Brain::Brain(const Brain &cpy) {
    // *this = cpy;
    for (int i = 0; i < 100; i++) 
        this->ideas[i] = cpy.ideas[i];
}

Brain &Brain::operator=(const Brain &cpy) {
    if (this != &cpy)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = cpy.ideas[i];
    }
    return (*this);
}
