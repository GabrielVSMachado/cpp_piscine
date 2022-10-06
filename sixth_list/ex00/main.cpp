/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:03:08 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/05 23:16:08 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <stdexcept>
#include <iostream>

int main ()
{
  {
    try {
      Bureaucrat newB("Gabriel", 170);
    }
    catch (std::exception const & e) {
      std::cerr << e.what() << std::endl;
    }
  }
  {
    try {
      Bureaucrat newB("Gabriel", 0);
    }
    catch (std::exception const & e) {
      std::cerr << e.what() << std::endl;
    }
  }
  {
    Bureaucrat newDefault;
    std::cout << newDefault << std::endl;
    try {
      newDefault.incrementGrade(150);
    }
    catch (std::exception const &e) {
      std::cerr << e.what() << std::endl;
    }
  }
  {
    Bureaucrat newDefault("Vitor", 10);
    try {
      newDefault.decresceGrade(141);
    }
    catch (std::exception const & e) {
      std::cerr << e.what() << std::endl;
    }
  }
  return 0;
}
