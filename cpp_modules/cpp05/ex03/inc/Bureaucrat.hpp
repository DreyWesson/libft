#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <stdexcept>

class AForm;

class Bureaucrat {
private:
    const std::string _name;
    int _grade;

public:
    Bureaucrat(void);
    Bureaucrat(const std::string name, int grade);
    Bureaucrat(const Bureaucrat &src);
    Bureaucrat &operator=(const Bureaucrat &src);
    ~Bureaucrat(void);

    void executeForm(AForm const & form);

	void signForm(AForm &f);
    
    const std::string getName(void) const;
    int getGrade(void) const;
    void increment(void);
    void decrement(void);

    class GradeTooHighException;
    class GradeTooLowException;    
};

class Bureaucrat::GradeTooHighException : public std::exception {
public:
    virtual const char* what() const throw() {
       return ("Grade is too high\n");
    }
};

class Bureaucrat::GradeTooLowException : public std::exception {
public:
    virtual const char* what() const throw() {
        return ("Grade is too low\n");
    }
};

std::ostream & operator<<(std::ostream &cout, Bureaucrat const & i);

#endif
