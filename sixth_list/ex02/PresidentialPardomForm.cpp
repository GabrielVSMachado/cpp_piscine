/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardomForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:15:28 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/12 13:22:35 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardomForm.hpp"
#include "BureaucracyConstitution.hpp"
#include <iostream>

PresidentialPardomForm::PresidentialPardomForm()
    : BureaucracyConstitution("DefaultPresident"),
      AForm("DefaultPresident", false, 25, 5) {}

PresidentialPardomForm::PresidentialPardomForm(std::string const &nameTarget)
    : BureaucracyConstitution(nameTarget), AForm(nameTarget, false, 25, 5) {}

PresidentialPardomForm::PresidentialPardomForm(
    PresidentialPardomForm const &other)
    : BureaucracyConstitution(other.getName()), AForm(other) {}

PresidentialPardomForm::~PresidentialPardomForm() {}

void PresidentialPardomForm::doTheExecution() const {
  std::cout << "The " << this->getName() << " has been pardoned by ";
  std::cout << "Zaphod Beeblebox." << std::endl;
}
