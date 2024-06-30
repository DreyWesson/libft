/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:35:23 by doduwole          #+#    #+#             */
/*   Updated: 2023/12/26 17:35:24 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
#define ARRAY_H

#include <stdexcept>


template< typename T >
class Array
{
private:
    T* _arr;
    unsigned int _arrSize;
public:
    Array() : _arr(NULL), _arrSize(0) {}

    Array(unsigned int n) : _arrSize(n) {
        _arr = new T[n];
        for (unsigned int i = 0; i < n; ++i)
            _arr[i] = T(); 
    }

    Array(const Array &src) : _arr(new T[src._arrSize]), _arrSize(src._arrSize) {
        for (unsigned int i = 0; i < _arrSize; ++i)
            _arr[i] = src._arr[i];
    }


    Array & operator=(Array const & cpy) {
        if (this != &cpy)
        {
            delete[] _arr;
            _arrSize = cpy._arrSize;
            _arr = new T[_arrSize];
            for (unsigned int i = 0; i < _arrSize; i++)
                _arr[i] = cpy._arr[i];
        }
        return *this;
    }

    ~Array() {
        delete[] _arr;
    }

    T & operator[](unsigned int idx) const {
        if (idx >= _arrSize)
            throw std::exception();
        return _arr[idx];
    }
    unsigned int size() const {
        return _arrSize;
    }
};

#endif