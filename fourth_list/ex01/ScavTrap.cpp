/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 01:49:25 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/23 21:27:47 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(void)
    : _hit(100), _energy(50), _attack(20), _name("scavtrap") {
  std::cout << "Default constructor from was ScavTrap called." << std::endl;
  return;
}

ScavTrap::ScavTrap(ScavTrap const &other) : ClapTrap(other) {
  *this = other;
  return;
}

ScavTrap::ScavTrap(std::string name)
    : _hit(100), _energy(50), _attack(20), _name(name) {
  std::cout << "ScavTrap know as " << name << " arrive!!!" << std::endl;
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

void ScavTrap::guardGate(void) {
  std::cout << "ScavTrap " << this->_name << " is now in the Gate keeper mode.";
  std::cout << std::endl;
  return;
}

void ScavTrap::attack(std::string const &target) {
  if (this->_energy == 0) {
    this->outOfEnergyWarning("ScavTrap");
  }
  if (this->_hit == 0) {
    this->deadObject("ScavTrap");
  }
  std::cout << "ScavTrap " << this->_name;
  std::cout << " attacks " << target << ", with " << this->_attack;
  std::cout << " points of damage!" << std::endl;
  --this->_energy;
}

void ScavTrap::beRepaired(unsigned int amount) {
  if (this->_energy == 0) {
    outOfEnergyWarning("ScavTrap");
    return;
  }
  if (this->_hit == 0) {
    this->deadObject("ScavTrap");
    return;
  }
  std::cout << "ScavTrap " << this->_name;
  std::cout << " repair itself by " << amount << " points!" << std::endl;
  --this->_energy;
  this->_hit += amount;
  this->_hit = this->_hit < 100 ? this->_hit : 100;
}

void ScavTrap::takeDamage(unsigned int amount) {
  if (this->_hit == 0) {
    this->deadObject("ScavTrap");
    return;
  }
  std::cout << "ScavTrap " << this->_name << " took " << amount;
  std::cout << " points of Damage!" << std::endl;
  this->_hit -= (this->_hit - amount) > this->_hit ? this->_hit : amount;
  if (this->_hit == 0) {
    std::cout << "ScavTrap " << this->_name << " Die!" << std::endl;
  }
}

std::string const &ScavTrap::getName(void) const { return this->_name; }
