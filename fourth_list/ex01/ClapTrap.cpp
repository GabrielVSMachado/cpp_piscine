/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 00:31:26 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/21 01:30:31 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _hit(10), _energy(10), _attack(0), _name("wilson") {
  std::cout << "Default Constructor was called." << std::endl;
  return;
}
ClapTrap::ClapTrap(ClapTrap const &other) {
  std::cout << "Copy assignment constructor was called." << std::endl;
  *this = other;
}

ClapTrap::ClapTrap(std::string name)
    : _hit(10), _energy(10), _attack(0), _name(name) {
  std::cout << "Constructor with name paramenter was called." << std::endl;
  return;
}

ClapTrap::~ClapTrap(void) {
  std::cout << "Destructor was called." << std::endl;
  return;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other) {
  this->_hit = other._hit;
  this->_name = other._name;
  this->_energy = other._energy;
  this->_attack = other._attack;
  return *this;
}

void ClapTrap::attack(std::string const &target) {
  if (this->_energy == 0) {
    outOfEnergyWarning("ClapTrap");
    return;
  }
  if (this->_hit == 0) {
    this->deadObject("ClapTrap");
    return;
  }
  std::cout << "ClapTrap " << this->_name;
  std::cout << " attacks " << target << ", causing " << this->_attack;
  std::cout << " points of damage!" << std::endl;
  --this->_energy;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (this->_energy == 0) {
    outOfEnergyWarning("ClapTrap");
    return;
  }
  if (this->_hit == 0) {
    this->deadObject("ClapTrap");
    return;
  }
  std::cout << "ClapTrap " << this->_name;
  std::cout << " repair itself by " << amount << " points!" << std::endl;
  --this->_energy;
  this->_hit += amount;
  this->_hit = this->_hit < 10 ? this->_hit : 10;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (this->_hit == 0) {
    this->deadObject("ClapTrap");
    return;
  }
  std::cout << "ClapTrap " << this->_name << " took " << amount;
  std::cout << " points of Damage!" << std::endl;
  this->_hit -= (this->_hit - amount) > this->_hit ? this->_hit : amount;
  if (this->_hit == 0) {
    std::cout << "ClapTrap " << this->_name << " Die!" << std::endl;
  }
}

void ClapTrap::deadObject(std::string const & type) const {
  std::cout << type << " " << this->_name;
  std::cout << " couldn't do anything because is Dead!" << std::endl;
  return;
}

void ClapTrap::outOfEnergyWarning(std::string const & type) const {
  std::cout << type << " " << this->_name << " Out of energy." << std::endl;
  return;
}
