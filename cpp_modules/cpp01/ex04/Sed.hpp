/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduwoledare <oduwoledare@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:20:32 by doduwole          #+#    #+#             */
/*   Updated: 2023/11/20 21:23:54 by oduwoledare      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_H
#define SED_H

#include <iostream>
#include <fstream>
#include <string>

void print_err(std::string msg);

std::string get_content(std::string filename, std::string &content);

std::string replace_filename(std::string filename);

void handle_replacement(char **argv, std::string content);

#endif