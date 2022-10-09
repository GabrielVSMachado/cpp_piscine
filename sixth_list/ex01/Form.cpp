/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:27:53 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/09 15:33:32 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
  : BureaucracyConstitution(), _isSigned(false),
  _requiredSign(150),_requiredExecute(150) {}

Form::Form(Form const &other)
: BureaucracyConstitution(other), _isSigned(other._isSigned),
_requiredSign(other._requiredSign), _requiredExecute(other._requiredExecute){}

Form::Form(
    std::string const &name,
    bool const &isSigned,
    unsigned int const &requiredSign,
    unsigned int const &requiredExecute) throw(GradeTLExcpt, GradeTHExcpt)
  : BureaucracyConstitution(name), _isSigned(isSigned),
  _requiredSign(requiredSign), _requiredExecute(requiredExecute) {

  if (requiredExecute > 150 || requiredSign > 150) {
    throw Form::GradeTooLowException();
  } else if (requiredSign < 1 || requiredExecute < 1) {
    throw Form::GradeTooHighException();
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
unsigned int const &Form::getExecuteGrade() const {
  return this->_requiredExecute;
}

void Form::beSigned(Bureaucrat const &bureaucrat)
throw(GradeTHExcpt, GradeTLExcpt) {
}
