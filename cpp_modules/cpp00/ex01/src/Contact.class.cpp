/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduwoledare <oduwoledare@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:55:50 by oduwoledare       #+#    #+#             */
/*   Updated: 2023/10/29 09:26:37 by oduwoledare      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Contact.class.hpp"

Contact::Contact(void) {
    return;
}

Contact::~Contact(void) {
    return;
}

std::string Contact::get_fname() const {
    return (this->_fname);
}

std::string Contact::get_lname() const {
    return (this->_lname);
}

std::string Contact::get_nickname() const {
    return (this->_nickname);
}

std::string Contact::get_phone_num() const {
    return (this->_phone_num);
}

std::string Contact::get_darkest_secret() const {
    return (this->_darkest_secret);
}

std::string Contact::_truncate(std::string val) {
    if (val.length() > 10) {
        val[9] = '.';
        val.erase(10, val.length() - 10);
    }
    return (val);
}

std::string Contact::_parse_str(std::string val, std::string type) {
    if (val == "")
        return ("");
    for (size_t i = 0; i < val.size(); i++) {
        if (!type.compare("str") && !isalpha(val[i])) {
            if (isspace(val[i]))
                continue;
            return ("");
        } else if (!type.compare("digit") && !isdigit(val[i]))
            return ("");
    }
    return (_truncate(val));
}

std::string Contact::set_fname(std::string first_name) {
    this->_fname = this->_parse_str(first_name, "str");
    return (this->_fname);
}

std::string Contact::set_lname(std::string last_name) {
    this->_lname = this->_parse_str(last_name, "str");
    return (this->_lname);
}

std::string Contact::set_nickname(std::string nickname) {
    this->_nickname = this->_parse_str(nickname, "str");
    return (this->_nickname);
}

std::string Contact::set_phone_num(std::string phone_number) {
    this->_phone_num = this->_parse_str(phone_number, "digit");
    return (this->_phone_num);
}

void Contact::set_darkest_secret(std::string darkest_secret) {
    this->_darkest_secret = this->_parse_str(darkest_secret, "mix");
}
