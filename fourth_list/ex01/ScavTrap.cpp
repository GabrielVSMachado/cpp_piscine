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

ScavTrap::ScavTrap(void) : ClapTrap("ScavTrap", 100, 50, 20) {
  std::cout << "Default constructor from was ScavTrap called." << std::endl;
  return;
}

ScavTrap::ScavTrap(ScavTrap const &other) : ClapTrap(other) {
  std::cout << "Copy assign operator from ScavTrap called." << std::endl;
  return;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20) {
  std::cout << "ScavTrap know as " << name << " arrive!!!" << std::endl;
  return;
}

ScavTrap::~ScavTrap(void) {
  std::cout << "Destructor for " << this->getName() << " called." << std::endl;
  return;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other) {
  this->setName(other.getName());
  this->setHit(other.getHit());
  this->setEnergy(other.getEnergy());
  this->setAttack(other.getAttack());
  return *this;
}

void ScavTrap::guardGate(void) {
  std::cout << "ScavTrap " << this->getName()
            << " is now in the Gate keeper mode.";
  std::cout << std::endl;
  return;
}

void ScavTrap::attack(std::string const &target) {
  if (this->getEnergy() == 0) {
    this->outOfEnergyWarning("ScavTrap");
    return;
  }
  if (this->getHit() == 0) {
    this->deadObject("ScavTrap");
    return;
  }
  std::cout << "ScavTrap " << this->getName();
  std::cout << " attacks " << target << ", with " << this->getAttack();
  std::cout << " points of damage!" << std::endl;
  this->setEnergy(this->getEnergy() - 1);
}
