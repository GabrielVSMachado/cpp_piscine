/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:55:02 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/14 00:20:36 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::HarlMemFn Harl::f[4] = {
  &Harl::_debug, &Harl::_error, &Harl::_info, &Harl::_warning
};

Harl::Harl(void) { return; }
Harl::~Harl(void) { return; }

void Harl::_debug(void) const {
  std::cout << "I love having extra bacon for my ";
  std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger. ";
  std::cout << "I really do!" << std::endl;
}

void Harl::_info(void) const {
  std::cout << "I cannot believe adding extra bacon cost more money. ";
  std::cout << "You didn't put enough bacon in my burguer! ";
  std::cout << "If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::_warning(void) const {
  std::cout << "I think I deserve to have some extra bacon for free. ";
  std::cout << "I've been coming for years whereas ";
  std::cout << "you starting working here since last month." << std::endl;
}

void Harl::_error(void) const {
  std::cout << "This is unacceptable! I want to speak with your manager now.";
  std::cout << std::endl;
}

void Harl::complain(std::string level) const {
  unsigned int nlevel = (level[0] % 16) - 4;
  (this->*(Harl::f[ nlevel < 4 ? nlevel : nlevel - 3 ]))();
}
