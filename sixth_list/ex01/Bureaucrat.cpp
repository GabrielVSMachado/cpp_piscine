/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 22:03:23 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/09 14:25:05 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include "Form.hpp"

Bureaucrat::Bureaucrat() : BureaucracyConstitution(), _grade(150) {}

Bureaucrat::Bureaucrat(Bureaucrat const &other)
    : BureaucracyConstitution(other), _grade(other._grade) {}

Bureaucrat::Bureaucrat(std::string const &name, unsigned int const &grade)
 throw(GradeTHExcpt, GradeTLExcpt) : BureaucracyConstitution(name) {
  if (grade < 1) {
    throw Bureaucrat::GradeTooHighException();
  } else if (grade > 150) {
    throw Bureaucrat::GradeTooLowException();
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

void Bureaucrat::signForm(Form &toSign) const {
  try {
    toSign.beSigned(*this);
    std::cout << this->getName() << " signed " << toSign.getName() << std::endl;
    return;
  }
  catch (Form::GradeTooLowException const &e) {
    std::cout << this->getName() << " couldn't sign " << toSign.getName();
    std::cout << " because " << e.what() << std::endl;
  }
}
