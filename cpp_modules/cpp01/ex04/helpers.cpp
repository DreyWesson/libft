/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:14:41 by doduwole          #+#    #+#             */
/*   Updated: 2023/11/21 13:36:17 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

void print_err(std::string msg) {
    std::cout << "\033[31m""Error""\033[0m" << std::endl;
    std::cout << "  " << msg << std::endl;
}

std::string get_content(std::string filename, std::string &content) {
    std::ifstream file;
    std::string line;

    file.open(filename.c_str(), std::ios::in);
    if (file.is_open())
        while (getline(file, line, '\0'))
            content.append(line);
    file.close();
    return (content);
}

std::string rename_file(std::string filename) {
    size_t pos = filename.rfind(".");

    if (pos != std::string::npos)
        filename = filename.substr(0, pos);
    filename += ".replace";
    return (filename);
}

void handle_replacement(char **argv, std::string content) {
    int i = 0;
    int len;
    std::string new_filename;

    new_filename = rename_file(argv[1]);
    len = std::string(argv[2]).size();
    std::ofstream file(new_filename.c_str());
    if (!file.is_open())
        print_err("File error");
    else
        while (content[i]) {
            if (content[i] == argv[2][0] && std::string(argv[2]).compare(content.substr(i, len)) == 0) {
                file << argv[3];
                i += len - 1;
            } else
                file << content[i];
            i++;
        }
}
