/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduwoledare <oduwoledare@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:36:11 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/29 20:16:05 by oduwoledare      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/Phonebook.class.hpp"


PhoneBook::PhoneBook() {
    std::cout << CONTACT_SIZE << std::endl;
    this->_id = 0;
}

PhoneBook::~PhoneBook() {
    std::cout << "Phonebook destructor called!" << std::endl;
}

void PhoneBook::_add_contact() {
    int flag = 0;
    std::string first_name = "";
    std::string last_name = "";
    std::string nickname = "";
    std::string darkest_secret = "";
    std::string phone_number = "";

    _parse_input(first_name, &flag, "First name");
    _parse_input(last_name, &flag, "Last name");
    _parse_input(nickname, &flag, "Nickname");
    _parse_input(phone_number, &flag, "Phone num");
    _parse_input(darkest_secret, &flag, "Darkest secret");


    this->_id++;
    if (std::cin.good())
        std::cout << "\033[32m""Contact added!!!" << std::endl;
    std::cin.clear();
}

void PhoneBook::_search_contact(void) const {
    int id = 0;
    std::string str;
    _view_contacts();
    std::cout << "Enter the contact\'s ID: " << std::endl;
    std::cout << "> ";
    std::cin >> str;
    id = atoi(str.c_str());
    if (std::cin.fail() || (id < 0) || (id > (CONTACT_SIZE - 1)) || str.length() > 1)
        _print_err("Out of range. Pls, enter a valid index!");
    else {
        if (_contacts[id].get_fname() == "" || _contacts[id].get_lname() == "")
            _print_err("Phone index doesn't exist yet. Add more contact");
        else
            _print_contact(id);
    }
    std::cin.clear();
    std::cin.ignore(10000, '\n');
}

void PhoneBook::handle_phone_book(void) {
    std::string cmd;

    this->_user_manual();
    std::cout << "\033[32m""> ""\033[0m";
    while (getline(std::cin, cmd)) {
        if (!cmd.compare("ADD"))
            _add_contact();
        else if (!cmd.compare("SEARCH"))
            _search_contact();
        else if (!cmd.compare("EXIT"))
            break;
        else
            _print_err("   cmd not found. Pls, use the manual!");
        std::cout << "\033[32m""> ""\033[0m";
    }
}
