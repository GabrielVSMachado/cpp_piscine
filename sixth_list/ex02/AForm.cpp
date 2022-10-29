/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:27:53 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/29 14:30:02 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <ostream>

AForm::AForm()
  : _isSigned(false), _name("AForm"),
  _requiredSign(150),_requiredExecute(150) {}

AForm::AForm(AForm const &other)
: _isSigned(other._isSigned), _name(other._name),
_requiredSign(other._requiredSign), _requiredExecute(other._requiredExecute){}

AForm::AForm(
    std::string const &name,
    bool const &isSigned,
    unsigned int const &requiredSign,
    unsigned int const &requiredExecute) throw(GradeTLExcpt, GradeTHExcpt)
  : _isSigned(isSigned), _name(name),
  _requiredSign(requiredSign), _requiredExecute(requiredExecute) {

  if (requiredExecute > 150 || requiredSign > 150) {
    throw GradeTooLowException();
  } else if (requiredSign < 1 || requiredExecute < 1) {
    throw GradeTooHighException();
  }
}

AForm& AForm::operator=(AForm const &other) {
  if (this == &other) { return *this; }
  this->_isSigned = other._isSigned;
  return *this;
}

AForm::~AForm() {}

bool const &AForm::isSigned() const { return this->_isSigned; }
unsigned int const &AForm::getSignGrade() const { return this->_requiredSign; }
std::string const &AForm::getName() const { return this->_name; }
unsigned int const &AForm::getExecuteGrade() const {
  return this->_requiredExecute;
}

void AForm::beSigned(Bureaucrat const &bureaucrat)
throw(GradeTLExcpt) {
  if (bureaucrat.getGrade() > this->getSignGrade()) {
    throw GradeTooLowException();
  }
  this->_isSigned = true;
}

AForm::NotSignException::NotSignException() {}

char const *AForm::NotSignException::what() const throw() {
  return "This form need to be signed before any action.";
}

void AForm::execute(Bureaucrat const &bureaucrat) const
throw(NotSignException, GradeTLExcpt) {
  if (!this->_isSigned) {
    throw NotSignException();
  } else if (bureaucrat.getGrade() > this->_requiredExecute) {
    throw GradeTLExcpt();
  }
  this->doTheExecution();
}

std::ostream& operator<<(std::ostream &o, AForm const &f) {
  o << f.getName() << ", form grade required to sign " << f.getSignGrade();
  o << ", grade required to execute " << f.getExecuteGrade();
  o << ". This form is signed? " << f.isSigned();
  return o;
}
