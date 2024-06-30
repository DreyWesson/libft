/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:35:35 by doduwole          #+#    #+#             */
/*   Updated: 2023/12/26 17:51:55 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib> 
#include <ctime>

template<typename T>
void testArray(const Array<T>& array) {
    std::cout << "Array size: " << array.size() << std::endl;

    std::cout << "Array elements: ";
    for (size_t i = 0; i < array.size(); ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    Array<T> modifiedArray(array);
    modifiedArray[1] = T();
    std::cout << "Modified Array: ";
    for (size_t i = 0; i < modifiedArray.size(); ++i) {
        std::cout << modifiedArray[i] << " ";
    }
    std::cout << std::endl;
}

template<typename T>
std::string convertToString(const T& value) {
    std::stringstream s;
    s << value;
    return s.str();
}

int main() {
    try {
        Array<int> intArray(5);
        for (size_t i = 0; i < intArray.size(); ++i)
            intArray[i] = static_cast<int>(i * 2);
        testArray(intArray);

        Array<double> doubleArray(3);
        for (size_t i = 0; i < doubleArray.size(); ++i) {
            doubleArray[i] = static_cast<double>(i * 1.5);
        }
        testArray(doubleArray);

        Array<std::string> stringArray(4);
        for (size_t i = 0; i < stringArray.size(); ++i) {
            stringArray[i] = "Element-" + convertToString(i);
        }
        testArray(stringArray);
        std::cout << "Accessing an element out of bounds will throw an exception now\n";
        std::cout << intArray[intArray.size()] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}



// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;
//     return 0;
// }
