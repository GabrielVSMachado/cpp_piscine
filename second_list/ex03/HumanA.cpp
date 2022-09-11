/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 10:36:22 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/11 10:39:16 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon)
    : _weapon(weapon), _name(name) { return; }

HumanA::~HumanA(void) { return; }

void HumanA::attack(void) const {
  std::cout << this->_name << " attacks with their ";
  std::cout << this->_weapon.getType() << std::endl;
}
