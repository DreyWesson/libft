#include "Harl.hpp"

#include "Harl.hpp"

int main( int argc, char **argv ) {

    if (argc != 2) 
        return (std::cout << "It needs one argument\n", 1);
    Harl        harl;

    harl.complain(argv[1]);
    return (0);
}