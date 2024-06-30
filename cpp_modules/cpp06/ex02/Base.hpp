/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drey <drey@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:37:39 by drey              #+#    #+#             */
/*   Updated: 2023/12/23 15:37:40 by drey             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>

class Base
{
public:
    virtual ~Base();
};

Base    *generate(void);
void    identify(Base *ptr);
void    identify(Base &ptr);

#endif