/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drey <drey@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:37:59 by drey              #+#    #+#             */
/*   Updated: 2023/12/23 15:38:00 by drey             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

void test_null() {
    Base *ptr = generate();
    identify(ptr);

    Base *nullPtr = NULL;
    identify(nullPtr);
    delete ptr;

}

int main() {
	Base* ptr = generate();
    Base *ptrA = generate();
    Base *ptrB = generate();
    Base *ptrC = generate();

	Base& refr = *ptr;

	identify(ptr);
	identify(refr);

    std::cout << "Testing identify(Base *ptr):" << std::endl;
    identify(ptrA);
    identify(ptrB);
    identify(ptrC);

    std::cout << "\nTesting identify(Base &ptr):" << std::endl;
    identify(*ptrA);
    identify(*ptrB);
    identify(*ptrC);

    test_null();
	delete ptr;
    delete ptrA;
    delete ptrB;
    delete ptrC;
    std::cout << "\n\n";
    return 0;
}
