/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduwoledare <oduwoledare@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:27:17 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/29 15:31:49 by oduwoledare      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
#define CONTACT_CLASS_H

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <stdlib.h>

class Contact {
private:
    std::string _lname;
    std::string _fname;
    std::string _nickname;
    std::string _phone_num;
    std::string _darkest_secret;

    std::string _parse_str(std::string val, std::string type);

    std::string _truncate(std::string);

public:
    Contact(void);

    ~Contact(void);

    std::string get_lname(void) const;

    std::string get_fname(void) const;

    std::string get_nickname(void) const;

    std::string get_phone_num(void) const;

    std::string get_darkest_secret(void) const;

    std::string set_fname(std::string);

    std::string set_lname(std::string);

    std::string set_nickname(std::string);

    std::string set_phone_num(std::string);

    void set_darkest_secret(std::string);
};

#endif
