/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 02:03:03 by doduwole          #+#    #+#             */
/*   Updated: 2023/12/06 05:32:54 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>

class Brain
{
private:

protected:
    std::string ideas[100];
    
public:
    Brain(void);
    Brain(const Brain &cpy);
    Brain &operator=(const Brain &cpy);
    virtual ~Brain(void);
};


#endif