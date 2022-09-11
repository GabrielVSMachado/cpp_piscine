/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:15:38 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/10 22:33:12 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) { return; }
Zombie::~Zombie(void) {
  std::cout << "Killer: " << "Headshot!!! ";
  std::cout << this->_name << " Die." << std::endl;
  return;
}

Zombie::Zombie(std::string name) : _name(name) { return; }

void Zombie::announce(void) const {
  std::cout << this->_name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie& Zombie::operator=(std::string name) {
  this->_name = name;
  return *this;
}
