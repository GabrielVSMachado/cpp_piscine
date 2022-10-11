/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:55:16 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/10 23:33:25 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "BureaucracyConstitution.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("DefaultTarget", false, 145, 137) {};

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &nameTarget)
    : BureaucracyConstitution(nameTarget), AForm(nameTarget, false, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other)
    : BureaucracyConstitution(other.getName()),
    AForm(other.getName(), other.isSigned(), 145, 137) {}

ShrubberyCF& ShrubberyCreationForm::operator=(ShrubberyCF const &other) {
  if (this == &other) { return *this; }
  *this = ShrubberyCreationForm(other);
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {};

void ShrubberyCreationForm::doTheExecution() const {
  std::ofstream fileWrite;
  std::string tmp = this->getName() + "_shrubbery";
  fileWrite.open(tmp.c_str(), std::ofstream::trunc | std::ofstream::out);
  if (fileWrite.fail()) {
    std::cerr << "Failed to open file to write." << std::endl;
    return;
  }
  fileWrite << TREE << std::endl;
  fileWrite.close();
}
