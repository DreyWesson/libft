/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:20:40 by doduwole          #+#    #+#             */
/*   Updated: 2023/12/23 12:20:41 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/ScalarConverter.hpp"

int main( int ac, char ** av )
{
    if ( ac != 2 )
        return (std::cout << "Usage: ./convert <value> \n", 1);
    
    std::string str(av[1]);
    ScalarConverter::convert(str);
    return (0);
}

