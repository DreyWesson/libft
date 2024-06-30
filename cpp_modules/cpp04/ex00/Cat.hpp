/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:31:18 by doduwole          #+#    #+#             */
/*   Updated: 2023/12/06 23:37:29 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
private:

protected:

    
public:
    Cat(void);
    Cat(const Cat &cpy);
    Cat &operator=(const Cat &cpy);
    ~Cat(void);
    
    virtual void makeSound(void) const;
};

class WrongCat : public WrongAnimal
{
private:

protected:

    
public:
    WrongCat(void);
    WrongCat(const WrongCat &cpy);
    WrongCat &operator=(const WrongCat &cpy);
    ~WrongCat(void);
    
    void makeSound(void) const;
};

#endif