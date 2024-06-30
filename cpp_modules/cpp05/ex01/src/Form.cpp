#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"

Form::Form(const std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _isSigned(false) {
    std::cout << gradeToSign << "DEBUG\n";
    if (gradeToSign < 1 || gradeToExecute < 1) {

        throw Form::GradeTooHighException();
    }
    else if (gradeToSign > 150 || gradeToExecute > 150) {

        throw Form::GradeTooLowException();
    }
}

Form::~Form() {}

Form::Form(const Form &src) : _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {}

Form &Form::operator=(const Form &src) {
    if (this != &src) {
        this->_isSigned = src.getSign();
    }
    return (*this);
}

std::string Form::getName(void) const {
      return (this->_name);  
}

int Form::getGradeToExecute(void) const {
    return (this->_gradeToExecute);
}

int Form::getGradeToSign(void) const {
    return (this->_gradeToSign);
}

bool Form::getSign(void) const {
	return (_isSigned);
}

void Form::beSigned(const Bureaucrat &b) {
    if (b.getGrade() > _gradeToSign)
        throw Form::GradeTooLowException();
    _isSigned = true;
}

/**
 * Overloaded Insertion Operators
*/
std::ostream & operator<<(std::ostream &cout, Form const & src) {
    cout << "#############################################\n";
    cout << "#            Form's Information\n";
    cout << "#  Name: ""\033[33m" << src.getName() << "\033[0m""\n";
    cout << "#  isSigned: ""\033[33m" << src.getSign() << "\033[0m""\n";
    cout << "#  gradeToSign: ""\033[33m" << src.getGradeToSign() << "\033[0m""\n";
    cout << "#  gradeToSign: ""\033[33m" << src.getGradeToExecute() << "\033[0m""\n";
    cout << "#############################################\n";
    return (cout);
}
