/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:41:56 by doduwole          #+#    #+#             */
/*   Updated: 2023/12/06 23:37:51 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
#define DOG_H

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal
{
private:

protected:

    
public:
    Dog(void);
    Dog(const Dog &cpy);
    Dog &operator=(const Dog &cpy);
    ~Dog(void);

    virtual void makeSound(void) const;
};

#endif