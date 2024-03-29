/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:03:08 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/29 13:18:19 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main ()
{
  {
    try {
      Form test("name", false, 151, 1);
    }
    catch (std::exception const &e) {
      std::cerr << e.what() << std::endl;
    }
  }
  {
    try {
      Form test("name", false, 1, 151);
    }
    catch (std::exception const &e) {
      std::cerr << e.what() << std::endl;
    }
  }
  {
    try {
      Form test("name", false, 1, 0);
    }
    catch (std::exception const &e) {
      std::cerr << e.what() << std::endl;
    }
  }
  {
    try {
      Form test("name", false, 0, 1);
    }
    catch (std::exception const &e) {
      std::cerr << e.what() << std::endl;
    }
  }
  {
    Bureaucrat b("Gabriel", 43);
    Form f("42Test", false, 42, 1);

    b.signForm(f);
  }
  {
    Form f("42Test", false, 42, 1);

    std::cout << f << std::endl;
  }
  return 0;
}
