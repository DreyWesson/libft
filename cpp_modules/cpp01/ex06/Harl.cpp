#include "Harl.hpp"

Harl::Harl(void) {}

Harl::~Harl(void) {}

void Harl::debug(void) {
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
              << std::endl;
}

void Harl::info(void) {
    std::cout
            << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"
            << std::endl;
}

void Harl::warning(void) {
    std::cout
            << "I think I deserve to have some extra bacon for free. I've been coming foryears whereas you started working here since last month."
            << std::endl;
}

void Harl::error(void) {
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
    int i = 0;
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    while (i < 4 && levels[i].compare(level))
        i++;
    switch (i)
    {
        case    0:
        {
            std::cout << "[" << levels[0] << "]" << std::endl;
            this->debug();
            std::cout << std::endl;
        }
        case    1:
        {
            std::cout << "[" << levels[1] << "]" << std::endl;
            this->info();
            std::cout << std::endl;
        } 
        case    2:
        {
            std::cout << "[" << levels[2] << "]" << std::endl;
            this->warning();
            std::cout << std::endl;
        } 
        case    3:
        {
            std::cout << "[" << levels[3] << "]" << std::endl;
            this->error();
            std::cout << std::endl;
            break ;
        } 
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}

void Harl::print_welcome(void)
{
        std::cout << "#############################################" << std::endl;
    std::cout << "#                                           #" << std::endl;
    std::cout << "#        Welcome to Harl Program            #" << std::endl;
    std::cout << "#     01. ""\033[32m""ENTER LEVEL" "\033[0m""                       #" << std::endl;
    std::cout << "#     02. ""\033[31m""EXIT" "\033[0m""                              #" << std::endl;
    std::cout << "#                                           #" << std::endl;
    std::cout << "#   ""\033[3m""Levels: DEBUG, INFO, WARNING and ERROR  #""\033[0m" << std::endl;
    std::cout << "#############################################" << std::endl;
}
