/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:38:26 by doduwole          #+#    #+#             */
/*   Updated: 2023/12/19 12:38:44 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _isSigned(false) {
    if (gradeToSign < 1)
        throw AForm::GradeTooHighException();
    else if (gradeToSign > 150)
        throw AForm::GradeTooLowException();
    if (gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    else if (gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::~AForm() {}

void AForm::checkPermission(Bureaucrat const & executor) const
{
    if (!getSign())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();
}

AForm::AForm(const AForm &src) : _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {}

AForm &AForm::operator=(const AForm &src) {
    if (this != &src)
        this->_isSigned = src.getSign();
    return (*this);
}

std::string AForm::getName(void) const {
      return (this->_name);  
}


int AForm::getGradeToSign(void) const {
    return (this->_gradeToSign);
}

int AForm::getGradeToExecute(void) const {
    return (this->_gradeToExecute);
}

bool AForm::getSign(void) const {
	return (_isSigned);
}

void AForm::beSigned(const Bureaucrat &b) {
    if (b.getGrade() > _gradeToSign)
        throw AForm::GradeTooLowException();
    _isSigned = true;
}

std::ostream & operator<<(std::ostream &cout, AForm const & src) {
    cout << "#############################################\n";
    cout << "#            AForm's Information\n";
    cout << "#  Name: ""\033[33m" << src.getName() << "\033[0m""\n";
    cout << "#  isSigned: ""\033[33m" << src.getSign() << "\033[0m""\n";
    cout << "#  gradeToSign: ""\033[33m" << src.getGradeToSign() << "\033[0m""\n";
    cout << "#############################################\n";
    return (cout);
}
