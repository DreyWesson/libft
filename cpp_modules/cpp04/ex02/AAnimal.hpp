/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:25:40 by doduwole          #+#    #+#             */
/*   Updated: 2023/12/07 00:17:45 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include "Brain.hpp"

class AAnimal
{
private:

protected:
    std::string type;
    
public:
    AAnimal(void);
    AAnimal(const AAnimal &cpy);
    AAnimal &operator=(const AAnimal &cpy);
    virtual ~AAnimal(void);

    virtual void makeSound(void) const = 0;
    void setType(std::string type);
    std::string getType(void) const;
};

class WrongAnimal
{
private:

protected:
    std::string type;
    
public:
    WrongAnimal(void);
    WrongAnimal(const WrongAnimal &cpy);
    WrongAnimal &operator=(const WrongAnimal &cpy);
    virtual ~WrongAnimal(void);

    void makeSound(void) const;
    void setType(std::string type);
    std::string getType(void) const;
};

#endif