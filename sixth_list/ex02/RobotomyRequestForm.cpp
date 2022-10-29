/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:15:14 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/29 14:41:47 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(std::string const &nameTarget)
    : AForm(nameTarget, false, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other)
    : AForm(other) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::doTheExecution() const {
  std::cout << "Fi foo fuuu" << std::endl;
  std::cout << "The " << this->getName()
            << " has been robotomized successfully";
  std::cout << " 50% of the time." << std::endl;
}
