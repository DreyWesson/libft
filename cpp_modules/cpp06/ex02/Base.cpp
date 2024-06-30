/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drey <drey@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:36:23 by drey              #+#    #+#             */
/*   Updated: 2023/12/23 15:36:24 by drey             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {
    std::cout << "base destructor called" << std::endl;
}

Base *generate(void)
{
	srand(time(NULL));
    int i = rand();
    switch(i % 3) {
        case 0:
            std::cout << "type A created" << std::endl;
            return new A;
        case 1:
            std::cout << "Type B created" << std::endl;
            return new B;
        case 2:
            std::cout << "Type C created" << std::endl;
            return new C;
    }
    return (NULL);
}

void identify(Base *p)
{
    if (!p) {
        std::cout << " - pointer is null" << std::endl;
        return;
    }
    if (dynamic_cast<A *>(p))
        std::cout << p << " - pointer of type: A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << p << " - pointer of type: B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << p << " - pointer of type: C" << std::endl;
    else
        std::cout << " - cannot identify pointer type" << std::endl;
}

void identify(Base &p)
{
    try {
        A &Aptr = dynamic_cast<A&>(p);
        std::cout << &Aptr << " - reference of type: A" << std::endl;
    } catch (const std::bad_cast&) {
        try {
            B &Bptr = dynamic_cast<B&>(p);
            std::cout << &Bptr << " - reference of type: B" << std::endl;
        } catch (const std::bad_cast&) {
            try {
                C &Cptr = dynamic_cast<C&>(p);
                std::cout << &Cptr << " - reference of type: C" << std::endl;
            } catch (const std::bad_cast&) {
                std::cerr << "Cannot identify reference type" << std::endl;
            }
        }
    }
}
