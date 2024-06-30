/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:03:24 by doduwole          #+#    #+#             */
/*   Updated: 2023/12/09 18:45:52 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
#define CURE_H

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
public:
    Cure(void);
    Cure(const Cure &cpy);
    Cure &operator=(const Cure &cpy);
    virtual ~Cure(void);

    virtual AMateria* clone() const;
    virtual void        use(ICharacter& target);
};

#endif