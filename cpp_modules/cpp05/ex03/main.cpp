#include "./inc/AForm.hpp"
#include "./inc/Bureaucrat.hpp"
#include "./inc/PresidentialPardonForm.hpp"
#include "./inc/RobotomyRequestForm.hpp"
#include "./inc/ShrubberyCreationForm.hpp"
#include "./inc/Intern.hpp"

void validforms() {

    Intern intern;

    try {
        AForm* form1 = intern.makeForm("presidential pardon", "Target1");
        delete form1;

        AForm* form2 = intern.makeForm("robotomy request", "Target2");
        delete form2;

        AForm* form3 = intern.makeForm("shrubbery creation", "Target3");
        delete form3;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
void invalidForms() {
    Intern intern;

    try {
        AForm* invalidForm = intern.makeForm("invalid form", "Target");
        delete invalidForm;
    } catch (const std::exception& e) {
        std::cerr << "Error creating invalid form: " << e.what() << std::endl;
    }

}

int main() {
    Intern someRandomIntern;
    AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");

    if (rrf != NULL) {
        Bureaucrat bureaucrat("John Doe", 50);

        // Sign the form before executing
        try {
            bureaucrat.signForm(*rrf);
        } catch (const std::exception& e) {
            std::cerr << "Error signing the form: " << e.what() << std::endl;
            return 1;
        }

        // Execute the form
        try {
            bureaucrat.executeForm(*rrf);
        } catch (const std::exception& e) {
            std::cerr << "Error executing the form: " << e.what() << std::endl;
        }
        delete rrf;
    } else {
        std::cerr << "Error creating the form." << std::endl;
    }
    // invalidForms();
    // validforms();
    return 0;
}
