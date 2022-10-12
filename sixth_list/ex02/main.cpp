/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:03:08 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/10 23:29:43 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>
#include <iostream>
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardomForm.hpp"

int main ()
{
  {
    ShrubberyCreationForm test;
  }
  {
    ShrubberyCreationForm form("Gondor");
    Bureaucrat regent("Denetor II", 144);
    try {
      form.execute(regent);
    }
    catch (AForm::NotSignException const &e) {
      std::cerr << e.what() << std::endl;
    }
  }
  {
    ShrubberyCreationForm form("Gondor");
    Bureaucrat regent("Denetor II", 144);
    try {
      regent.signForm(form);
      form.execute(regent);
    }
    catch (AForm::GradeTLExcpt const &e) {
      std::cerr << e.what() << std::endl;
    }
  }
  {
    ShrubberyCreationForm form("Gondor");
    Bureaucrat regent("Denetor II", 137);
    regent.signForm(form);
    regent.executeForm(form);
  }
  {
    ShrubberyCreationForm form("Gondor");
    Bureaucrat regent("Denetor II", 144);
    regent.signForm(form);
    regent.executeForm(form);
  }
  {
    RobotomyRequestForm form("TestRobotomy");
    Bureaucrat bumblebee("Bumblebee", 73);
    try {
      form.execute(bumblebee);
    }
    catch (RobotomyRequestForm::NotSignException const &e) {
      std::cout << "The Robotomy Failed." << std::endl;
      std::cerr << e.what() << std::endl;
    }
  }
  {
    RobotomyRequestForm form("TestRobotomy");
    Bureaucrat bumblebee("Bumblebee", 73);
    try {
      bumblebee.executeForm(form);
    }
    catch (std::exception const &e) {
      std::cerr << e.what() << std::endl;
    }
  }
  {
    PresidentialPardomForm form("Trump");
    Bureaucrat bumblebee("Bumblebee", 73);
    try {
      bumblebee.signForm(form);
      bumblebee.executeForm(form);
    }
    catch (std::exception const &e) {
      std::cerr << e.what() << std::endl;
    }
  }
  return 0;
}
