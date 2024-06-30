/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:31:18 by doduwole          #+#    #+#             */
/*   Updated: 2023/12/07 00:16:04 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
private:
    Brain* brain;

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
