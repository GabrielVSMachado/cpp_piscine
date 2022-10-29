/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:27:53 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/29 13:17:01 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <ostream>

Form::Form()
  : _isSigned(false), _name("Form"), _requiredSign(150),
  _requiredExecute(150) {}

Form::Form(Form const &other)
  : _isSigned(other._isSigned), _name(other._name),
_requiredSign(other._requiredSign), _requiredExecute(other._requiredExecute) {}

Form::Form(
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

Form& Form::operator=(Form const &other) {
  if (this == &other) { return *this; }
  *this = Form(other);
  return *this;
}

Form::~Form() {}

bool const &Form::isSigned() const { return this->_isSigned; }
unsigned int const &Form::getSignGrade() const { return this->_requiredSign; }
std::string const &Form::getName() const { return this->_name; }
unsigned int const &Form::getExecuteGrade() const {
  return this->_requiredExecute;
}

void Form::beSigned(Bureaucrat const &bureaucrat) throw(GradeTLExcpt) {
  if (bureaucrat.getGrade() > this->getSignGrade()) {
    throw GradeTooLowException();
  }
  this->_isSigned = true;
}

std::ostream& operator<<(std::ostream &o, Form const &f) {
  o << f.getName() << ", form grade required to sign " << f.getSignGrade();
  o << ", grade required to execute " << f.getExecuteGrade();
  o << ". This form is signed? " << f.isSigned();
  return o;
}
