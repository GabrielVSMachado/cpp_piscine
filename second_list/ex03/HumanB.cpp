/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 11:27:23 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/11 11:33:03 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) { return; }
HumanB::~HumanB(void) { return; }

void HumanB::attack(void) const {
  std::cout << this->_name << " attacks with their ";
  std::cout << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& weapon) {
  this->_weapon = &weapon;
}
