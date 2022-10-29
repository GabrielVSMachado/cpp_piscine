/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:55:16 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/29 14:38:14 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Exceptions.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : Form("DefaultTarget", false, 145, 137) {};

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &nameTarget)
    : Form(nameTarget, false, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other)
    : Form(other.getName(), other.isSigned(), 145, 137) {}

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
