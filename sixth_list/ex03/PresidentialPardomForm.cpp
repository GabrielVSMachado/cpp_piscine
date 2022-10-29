/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardomForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:15:28 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/29 14:42:47 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardomForm.hpp"
#include <iostream>

PresidentialPardomForm::PresidentialPardomForm()
    : Form("DefaultPresident", false, 25, 5) {}

PresidentialPardomForm::PresidentialPardomForm(std::string const &nameTarget)
    : Form(nameTarget, false, 25, 5) {}

PresidentialPardomForm::PresidentialPardomForm(
    PresidentialPardomForm const &other) : Form(other) {}

PresidentialPardomForm::~PresidentialPardomForm() {}

void PresidentialPardomForm::doTheExecution() const {
  std::cout << "The " << this->getName() << " has been pardoned by ";
  std::cout << "Zaphod Beeblebox." << std::endl;
}
