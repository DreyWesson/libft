#include "Harl.hpp"

#include "Harl.hpp"

int main(void) {

    std::string input;
    Harl harl;

    harl.print_welcome();
    do {
        std::cout << "Pls enter a level: ";
        getline(std::cin, input);
        harl.complain(input);
    } while (input.compare("exit"));

    return (0);
}