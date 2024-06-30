/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:59:45 by doduwole          #+#    #+#             */
/*   Updated: 2023/12/19 16:44:16 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/Bureaucrat.hpp"

void test_decrement() {
    Bureaucrat politico("Decepticon", 149);
    politico.decrement();
    politico.decrement();
    std::cout << politico;
}
void test_increment() {
    Bureaucrat politico("Optimus prime", 2);
    politico.increment();
    politico.increment();
    std::cout << politico;
}
int main(void) {
    try {
        test_decrement();
        //test_increment();
    } catch (Bureaucrat::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    } catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
