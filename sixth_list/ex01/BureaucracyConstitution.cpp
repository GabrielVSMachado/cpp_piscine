/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BureaucracyConstitution.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 13:57:30 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/09 14:20:28 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BureaucracyConstitution.hpp"

BureaucracyConstitution::BureaucracyConstitution() : _name("DefaultName") {}

BureaucracyConstitution::BureaucracyConstitution(
    BureaucracyConstitution const &other) : _name(other._name) {}

BureaucracyConstitution::BureaucracyConstitution(std::string const &name)
  : _name(name) {}

BureaucracyConstitution::~BureaucracyConstitution() {}

BureaucracyConstitution& BureaucracyConstitution::operator=(
    BureaucracyConstitution const &other) {
  if (this == &other) { return *this; }
  *this = BureaucracyConstitution(other);
  return *this;
}

std::string const &BureaucracyConstitution::getName() const {
  return this->_name;
}

BureaucracyConstitution::GradeTooHighException::GradeTooHighException() {}
char const *BureaucracyConstitution::GradeTooHighException::what() const throw()
{
  return "You must be the most low grade Bureaucrat I ever see.";
}

BureaucracyConstitution::GradeTooLowException::GradeTooLowException() {}
char const *BureaucracyConstitution::GradeTooLowException::what() const throw()
{
  return "You don't have enough grade to do this job.";
}
