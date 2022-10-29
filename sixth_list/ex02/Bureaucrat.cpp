/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 22:03:23 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/29 14:25:03 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _grade(150), _name("Bureaucrat") {}

Bureaucrat::Bureaucrat(Bureaucrat const &other)
    : _grade(other._grade), _name(other._name) {}

Bureaucrat::Bureaucrat(std::string const &name, unsigned int const &grade)
 throw(GradeTHExcpt, GradeTLExcpt) : _name(name) {
  if (grade < 1) {
    throw GradeTooHighException();
  } else if (grade > 150) {
    throw GradeTooLowException();
  }
  this->_grade = grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other) {
  if (this == &other) {
    return *this;
  }
  this->_grade = other._grade;
  return *this;
}

void Bureaucrat::incrementGrade(int const &value) throw(
    GradeTLExcpt, GradeTHExcpt) {
  Bureaucrat newValue(this->getName(), this->_grade - value);
  *this = newValue;
}

void Bureaucrat::decresceGrade(int const &value) throw(
    GradeTHExcpt, GradeTLExcpt) {
  this->incrementGrade(-value);
}

std::ostream& operator<<(std::ostream &out, Bureaucrat const &bureaucrat) {
  out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
  return out;
}

unsigned int const &Bureaucrat::getGrade() const { return this->_grade; }
std::string const &Bureaucrat::getName() const { return this->_name; }

void Bureaucrat::signForm(AForm &toSign) const {
  try {
    toSign.beSigned(*this);
    std::cout << this->_name << " signed " << toSign.getName() << std::endl;
    return;
  }
  catch (GradeTooLowException const &e) {
    std::cout << this->_name << " couldn't sign " << toSign.getName();
    std::cout << " because " << e.what() << std::endl;
  }
}

void Bureaucrat::executeForm(AForm const &form) const {
  try {
    form.execute(*this);
    std::cout << this->getName() << " execute " << form.getName() << std::endl;
    return;
  }
  catch (std::exception const &e) {
    std::cerr << this->getName() << " didn't execute " << form.getName()
              << " because " << e.what() << std::endl;
  }
}
