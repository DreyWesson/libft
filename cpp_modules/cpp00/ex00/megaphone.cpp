/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduwoledare <oduwoledare@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:47:58 by oduwoledare       #+#    #+#             */
/*   Updated: 2023/10/27 18:50:20 by oduwoledare      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv) {
    int i;
    int j;

    i = 1;
    if (argc > 1) {
        while (i < argc) {
            j = 0;
            while (argv[i][j] != '\0') {
                if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
                    argv[i][j] = std::toupper(argv[i][j]);
                std::cout << argv[i][j];
                j++;
            }
            i++;
        }
    } else if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << std::endl;
    return (0);
}
