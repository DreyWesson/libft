/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:03:37 by doduwole          #+#    #+#             */
/*   Updated: 2023/12/09 18:46:04 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
#define ICE_H

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{
private:

protected:
    
public:
    Ice(void);
    Ice(const Ice &cpy);
    Ice &operator=(const Ice &cpy);
    virtual ~Ice(void);

    virtual AMateria* clone() const;
    virtual void        use(ICharacter& target);
};

#endif