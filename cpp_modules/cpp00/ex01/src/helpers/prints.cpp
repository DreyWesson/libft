/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduwoledare <oduwoledare@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 19:31:03 by oduwoledare       #+#    #+#             */
/*   Updated: 2023/10/29 20:13:58 by oduwoledare      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Phonebook.class.hpp"

void PhoneBook::_print_contact(int id) const {
    std::cout << " ----------------------------------------------------------------- \n"
              << "|    ID    |First Name|Last Name | Nickname |Phone Num |DarkSecret|\n"
              << "|-----------------------------------------------------------------|\n"
              << '|' << std::setw(10) << id
              << '|' << std::setw(10) << _contacts[id].get_fname()
              << '|' << std::setw(10) << _contacts[id].get_lname()
              << '|' << std::setw(10) << _contacts[id].get_nickname()
              << '|' << std::setw(10) << _contacts[id].get_phone_num()
              << '|' << std::setw(10) << _contacts[id].get_darkest_secret()
              << '|' << std::endl
              << " ----------------------------------------------------------------- \n" << std::endl;
}

void PhoneBook::_view_contacts(void) const {
    std::cout << " ------------------------------------------- \n"
              << "|                Contact List               |\n"
              << "|-------------------------------------------|\n"
              << "|    ID    |First Name| Last Name| Nickname |\n"
              << "|-------------------------------------------|\n";

    for (int i = 0; i < 8; i++) {
        if (_contacts[i].get_fname().empty() && _contacts[i].get_lname().empty())
            break;
        std::cout << '|' << std::setw(10) << i;
        std::cout << '|' << std::setw(10) << _contacts[i].get_fname();
        std::cout << '|' << std::setw(10) << _contacts[i].get_lname();
        std::cout << '|' << std::setw(10) << _contacts[i].get_nickname();
        std::cout << '|' << std::endl;
        std::cout << "---------------------------------------------\n";
    }
}

void PhoneBook::_user_manual(void) const {
    std::cout << "#######################################" << std::endl;
    std::cout << "#                                     #" << std::endl;
    std::cout << "#     Welcome to awesome Phonebook    #" << std::endl;
    std::cout << "#     01. ""\033[32m""ADD" "\033[0m""                         #" << std::endl;
    std::cout << "#     02. ""\033[32m""SEARCH" "\033[0m""                      #" << std::endl;
    std::cout << "#     03. ""\033[31m""EXIT" "\033[0m""                        #" << std::endl;
    std::cout << "#                                     #" << std::endl;
    std::cout << "#######################################" << std::endl;

}

void PhoneBook::_input_err(int *flag, std::string type) const {

    std::cout << "\033[31m""Error:""\033[0m" << std::endl;
    std::cout << "  Invalid input: please enter a valid ""\033[33m" << type << "\033[0m" << std::endl;
    *flag = 1;
}

void PhoneBook::_print_err(std::string msg) const {
    std::cout << "\033[31m""Error:""\033[0m" << std::endl;
    std::cout << "  " << msg << std::endl;
}
