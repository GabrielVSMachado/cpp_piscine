/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 01:49:25 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/23 02:12:53 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
    : _hit(100), _energy(50), _attack(20), _name("scavtrap") {
  std::cout << "Default constructor ScavTrap called." << std::endl;
  return;
}

ScavTrap::ScavTrap(ScavTrap const &other) {
  *this = other;
  return;
}

ScavTrap::ScavTrap(std::string name)
    : _hit(100), _energy(50), _attack(20), _name(name) {
  std::cout << "Called constructor from ScavTrap." << std::endl;
  return;
}

ScavTrap::~ScavTrap(void) {
  std::cout << "Destructor from ScavTrap called." << std::endl;
  return;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other) {
  this->_name = other._name;
  this->_attack = other._attack;
  this->_energy = other._energy;
  this->_hit = other._hit;
  return *this;
}

void ScavTrap::attack(std::string& target) {
  if (this->_energy == 0) {
    this->outOfEnergyWarning("ScavTrap");
  }
  if (this->_hit == 0) {
    this->deadObject("ScavTrap");
  }
  std::cout << "ScavTrap " << this->_name;
  std::cout << " attacks " << target << ", causing " << this->_attack;
  std::cout << " points of damage!" << std::endl;
  --this->_energy;
}
