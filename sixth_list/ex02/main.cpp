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
#include "ShrubberyCreationForm.hpp"

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
  return 0;
}
