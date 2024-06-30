
#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include <iostream>
#include <stdexcept>

#include "AForm.hpp"

class PresidentialPardonForm :public AForm {
private:
    std::string _target;

public:
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm &src);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
    ~PresidentialPardonForm(void);
    void execute(Bureaucrat const & executor) const;
};

#endif
