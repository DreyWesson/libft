/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:19:15 by doduwole          #+#    #+#             */
/*   Updated: 2023/11/21 14:17:37 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int main(int argc, char **argv) {
    std::string content;
    std::string new_filename;

    content = "";
    if (argc != 4)
        return (print_err("This program takes 3 parameters"), 1);
    if (std::string(argv[2]).empty() || std::string(argv[3]).empty())
        return (print_err("String cannot be empty"), 2);
    if (get_content(argv[1], content).empty())
        return (print_err("Empty file or Error opening file"), 3);
            handle_replacement(argv, content);
    return (0);
}