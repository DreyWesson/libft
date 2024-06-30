#ifndef HARL_H

#define HARL_H

#include <iostream>
#include <string>

#define DEBUG "DEBUG"
#define INFO "INFO"
#define WARNING "WARNING"
#define ERROR "ERROR"

class Harl {
private:
    void info(void);

    void error(void);

    void debug(void);

    void warning(void);

public:
    Harl(void);

    ~Harl(void);

    void print_welcome(void);

    void complain(std::string level);
};

typedef void (Harl::*t_member)(void);

#endif