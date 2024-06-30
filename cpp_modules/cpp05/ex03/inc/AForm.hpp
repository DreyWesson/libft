/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:24:33 by doduwole          #+#    #+#             */
/*   Updated: 2023/12/19 12:34:24 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <stdexcept>


class Bureaucrat;

class AForm {
private:
    const std::string _name;
    const int _gradeToSign;
    const int _gradeToExecute;
	bool _isSigned;

public:
    AForm(const std::string name, int _gradeToSign, int _gradeToExecute);
    AForm(const AForm &src);
    AForm &operator=(const AForm &src);
    virtual ~AForm(void);

	void beSigned(const Bureaucrat &b);
    std::string getName(void) const;
	bool getSign(void) const;
	int getGradeToSign(void) const;
	int getGradeToExecute(void) const;

    virtual void execute(Bureaucrat const & executor) const = 0;
    void checkPermission(Bureaucrat const & executor) const;

    class GradeTooHighException;
    class GradeTooLowException;
    class FormNotSignedException;
    class FileOpenException;
};

class AForm::GradeTooHighException : public std::exception {
public:
    virtual const char* what() const throw() {
        return ("Grade is too high\n");
    }
};

class AForm::GradeTooLowException : public std::exception {
public:
    virtual const char* what() const throw() {
        return ("Grade is too low\n");
    }
};

class AForm::FormNotSignedException : public std::exception {
public:
    virtual const char* what() const throw() {
        return ("Form needs to be signed to be able to execute\n");
    }
};
class AForm::FileOpenException : public std::exception {
public:
    virtual const char* what() const throw() {
        return ("File fails to open\n");
    }
};

std::ostream & operator<<(std::ostream &cout, AForm const & i);

#endif
