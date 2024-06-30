/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:20:53 by doduwole          #+#    #+#             */
/*   Updated: 2023/12/23 12:20:54 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include <climits>
#include <cmath>

#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H


enum Type
{
    INVALID,
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    PSEUDO,
};
struct values {
    char charVal;
    int intVal;
    float floatVal;
    double doubleVal;
    bool validChar;
};

class ScalarConverter {
	private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(ScalarConverter const &cpy);
		ScalarConverter &operator=(ScalarConverter const &src);

    public:
        static void convert(std::string const &str);
};

#endif
