#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src), _target(src._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
    if (this != &src)
        this->_target = src._target;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    try {
        checkPermission(executor);
        std::cout << "Drilling noise!!!\n";
        std::srand(std::time(0)); // Seed random generator with current time
        (rand() % 2 == 0)
            ? std::cout << _target << " has been robotomized successfully!\n"
            : std::cout << "Robotomy failed for " << _target << ".\n";  
    } catch (const AForm::GradeTooLowException & e) {
        std::cerr << "GradeTooLowException: " << e.what();
        throw;
    } catch (const AForm::FormNotSignedException & e) {
        std::cerr << "FormNotSignedException: " << e.what();
        throw;
    } catch (const AForm::FileOpenException & e) {
        std::cerr << "FileOpenException: " << e.what();
        throw;
    } catch (const std::exception & e) {
        std::cerr << e.what();
        throw;
    }
}
