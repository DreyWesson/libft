#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <stdexcept>

class Bureaucrat;

class Form {
private:
    const std::string _name;
    const int _gradeToSign;
    const int _gradeToExecute;
	bool _isSigned;

public:
    Form(const std::string name, int _gradeToSign, int _gradeToExecute);
    Form(const Form &src);
    Form &operator=(const Form &src);
    ~Form(void);

	void beSigned(const Bureaucrat &b);
    std::string getName(void) const;
	bool getSign(void) const;
	int getGradeToSign(void) const;
	int getGradeToExecute(void) const;

    class GradeTooHighException;
    class GradeTooLowException;    
};

class Form::GradeTooHighException : public std::exception {
public:
    virtual const char* what() const throw() {
        return ("Grade is too high. Cannot instantiate Bureaucrat.");
    }
};

class Form::GradeTooLowException : public std::exception {
public:
    virtual const char* what() const throw() {
        return ("Grade is too low. Cannot instantiate Bureaucrat.");
    }
};

std::ostream & operator<<(std::ostream &cout, Form const & i);

#endif
