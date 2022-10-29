/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:03:08 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/29 16:15:35 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
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
    catch (Form::NotSignException const &e) {
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
    catch (GradeTLExcpt const &e) {
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
    catch (std::exception const &e) {
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
    PresidentialPardomForm form("The Wall");
    Bureaucrat Trump("Trump", 73);
    try {
      Trump.signForm(form);
      Trump.executeForm(form);
    }
    catch (std::exception const &e) {
      std::cerr << e.what() << std::endl;
    }
  }
  {
    Intern someRandomIntern;
    Bureaucrat randomBureaucrat("randomBureaucrat", 136);
    Form* shrc;

    shrc = someRandomIntern.makeForm("shrubbery creation", "Bender");
    try {
      shrc->beSigned(randomBureaucrat);
      shrc->execute(randomBureaucrat);
    }
    catch (std::exception const &e) {
      std::cerr << e.what() << '\n';
    }
  }
  {
    Intern someRandomIntern;
    Bureaucrat randomBureaucrat("randomBureaucrat", 136);
    Form* shrc;

    shrc = someRandomIntern.makeForm("creation", "Bender");
    if (!shrc) {
      std::cout << "Intern is stupid enough to their job.\n";
    }
  }
  return 0;
}
