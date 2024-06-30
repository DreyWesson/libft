#ifndef INTERN_H
#define INTERN_H

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
public:
    Intern();
    Intern( const Intern& src );
    Intern& operator=( const Intern& rhs );
    ~Intern();
    AForm* makeForm(const std::string formName, const std::string target);
};

#endif
