#include "../inc/Intern.hpp"

Intern::Intern() {}

Intern::Intern( const Intern& src ) {
    *this = src;
}

Intern& Intern::operator=( const Intern& rhs ) {
    ( void ) rhs;
    return (*this);
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string formName, const std::string target) {
    // std::string nameList[] = {
    //     "robotomy request",
    //     "presidential pardon",
    //     "shrubbery creation"
    // };
    // AForm*    forms[] = {
    //     new RobotomyRequestForm( target ),
    //     new PresidentialPardonForm( target ),
    //     new ShrubberyCreationForm( target )
    // };
    
    // for ( int i(0); i < 3; i++ ) {
    //     if ( formName == nameList[i] ) {
    //         std::cout << "Intern creates " << formName << std::endl;
    //         return forms[i];
    //     } else {
    //             delete forms[i];
    //     }
    // }
    // std::cout << "Error: Unknown form name \"" << formName << "\"\n";
    // return NULL;
    try {
        std::string nameList[] = {
            "robotomy request",
            "presidential pardon",
            "shrubbery creation"
        };
        AForm* forms[] = {
            new RobotomyRequestForm(target),
            new PresidentialPardonForm(target),
            new ShrubberyCreationForm(target)
        };

        AForm* createdForm = NULL;

        for (int i(0); i < 3; i++) {
            if (formName == nameList[i]) {
                std::cout << "Intern creates " << formName << std::endl;
                createdForm = forms[i];
            } else {
                delete forms[i];
            }
        }
        if (!createdForm)
            throw std::invalid_argument("Unknown form name \"" + formName + "\"");
        return createdForm;
    } catch (const std::exception& e) {
        std::cerr << "Error creating the form: " << e.what() << std::endl;
        return nullptr;
    }
}
