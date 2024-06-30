/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:05:42 by doduwole          #+#    #+#             */
/*   Updated: 2023/12/26 16:05:43 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVET_H
#define WHATEVET_H

#include <iostream>

template<typename T>
void    swap(T &x, T &y)
{
    T   tmp = x;
    x = y;
    y = tmp;
}

template<typename T>
T const & min(T const & x, T const & y)
{
    return (x < y ? x : y);
}

template<typename T>
T const & max(T const & x, T const & y)
{
    return (x > y ? x : y);
}

#endif