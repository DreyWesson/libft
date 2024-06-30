/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:56:47 by doduwole          #+#    #+#             */
/*   Updated: 2023/11/17 15:17:57 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

int main(void) {
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;
    std::cout << "Memory Addresses:" << std::endl;
    std::cout << "string: " << &str << std::endl;
    std::cout << "stringPTR: " << &stringPTR << std::endl;
    std::cout << "stringREF: " << &stringREF << std::endl << std::endl;

    std::cout << "Values:" << std::endl;
    std::cout << "string: " << str << std::endl;
    std::cout << "stringPTR: " << *stringPTR << std::endl;
    std::cout << "stringREF: " << stringREF << std::endl;
}
