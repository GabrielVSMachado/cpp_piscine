/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:17:00 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/29 16:15:13 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardomForm.hpp"
#include <iostream>

std::string Intern::validForms[] = {
  "shrubbery creation", "robotomy request", "presidential pardon"
};

Intern::Intern() {}

Intern::Intern(Intern const &other) { (Intern)other; }

Intern& Intern::operator=(Intern const &other) {
  (Intern)other;
  return *this;
}

Intern::~Intern() {}

Form* Intern::makeForm(std::string const &form, std::string const &formName) {
  std::size_t form_position = 0;
  for (; form_position < validForms->size() ; ++form_position) {
    if (form == validForms[form_position]) {
      break;
    }
  }
  switch (form_position) {
    case 0:
      std::cout << "Intern creates ShrubberyCreationForm\n";
      return new ShrubberyCreationForm(formName);
    case 1:
      std::cout << "Intern creates RobotomyRequestForm\n";
      return new RobotomyRequestForm(formName);
    case 2:
      std::cout << "Intern creates PresidentialPardomForm\n";
      return new PresidentialPardomForm(formName);
    default:
      std::cout << "Intern didn't create anything\n";
      return NULL;
  }
}
