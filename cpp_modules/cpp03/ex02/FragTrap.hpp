/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:03:55 by doduwole          #+#    #+#             */
/*   Updated: 2023/12/02 12:46:18 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:

public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(const FragTrap &cpy);
    FragTrap &operator=(const FragTrap &cpy);
    ~FragTrap();
    
    void print_welcome(std::string const_type);
    void highFivesGuys(void);
    void attack(std::string const & target);
};



#endif