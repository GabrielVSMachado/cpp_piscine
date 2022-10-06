/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 22:03:23 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/05 23:09:51 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <stdexcept>
#include <iostream>

Bureaucrat::Bureaucrat(void) : _name("NormalBureaucrat"), _grade(150) {}

Bureaucrat::Bureaucrat(Bureaucrat const &other)
    : _name(other._name), _grade(other._grade) {}

Bureaucrat::Bureaucrat(std::string const &name, unsigned int const &grade)
 throw(GradeTooHighExpt, GradeTooLowExpt) : _name(name) {
  if (grade < 1) {
    throw Bureaucrat::GradeTooHighException();
  } else if (grade > 150) {
    throw Bureaucrat::GradeTooLowException();
  }
  this->_grade = grade;
}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other) {
  if (this == &other) {
    return *this;
  }
  this->_grade = other._grade;
  return *this;
}

void Bureaucrat::incrementGrade(int const &value) throw(
    GradeTooLowExpt, GradeTooHighExpt) {
  Bureaucrat newValue(this->_name, this->_grade - value);
  *this = newValue;
}

void Bureaucrat::decresceGrade(int const &value) throw(
    GradeTooHighExpt, GradeTooLowExpt) {
  this->incrementGrade(-value);
}

std::ostream& operator<<(std::ostream &out, Bureaucrat const &bureaucrat) {
  out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
  return out;
}

std::string const &Bureaucrat::getName(void) const { return this->_name; }
unsigned int const &Bureaucrat::getGrade(void) const { return this->_grade; }

Bureaucrat::GradeTooHighException::GradeTooHighException() : std::exception() {}
char const *Bureaucrat::GradeTooHighException::what() const throw() {
  return "The bureaucracy don't allow you to have a high score.";
}


Bureaucrat::GradeTooLowException::GradeTooLowException() : std::exception() {}
char const *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Do you wanna be the most stupid bureaucrat ?";
}
