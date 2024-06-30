#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"


Bureaucrat::Bureaucrat(void) {
    // std::cout << "\033[2;37m""\033[3m" "BUREAUCRAT constructor called\n" "\033[0m";
}

Bureaucrat::Bureaucrat(const std::string name) : _name(name) {
    // std::cout << "\033[2;37m""\033[3m" "BUREAUCRAT parameterized constructor called\n" "\033[0m";
    std::cout << "_name: " << _name << "\n";
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
    // std::cout << "\033[2;37m""\033[3m" "BUREAUCRAT parameterized constructor called\n" "\033[0m";
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
    // std::cout << "\033[2;37m""\033[3m" "BUREAUCRAT destructor called\n" "\033[0m";
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {
    if (this != &src)
        this->_grade = src._grade;
    return (*this);
}

const std::string Bureaucrat::getName(void) const {
      return (this->_name);  
}

int Bureaucrat::getGrade(void) const {
    return (this->_grade);
}

void Bureaucrat::increment(void) {
    if (this->_grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade -= 1;

}

void Bureaucrat::decrement(void) {
    if (this->_grade >= 150)
        throw Bureaucrat::GradeTooLowException(); 
    this->_grade += 1;
}

/**
 * Overloaded Insertion Operators
*/
std::ostream & operator<<(std::ostream &cout, Bureaucrat const & src) {
    cout << src.getName() << ", bureaucrat grade " << src.getGrade();
    return (cout);
}

void Bureaucrat::signForm(Form& f) {
	try {
		    f.beSigned(*this);
		    std::cout << *this << " signed " << f.getName() << "\n";
	}
	catch(std::exception& e) {
			std::cout << *this << " couldn't sign " << f.getName() << " because " << e.what();
	}

}

