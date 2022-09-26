/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 21:13:48 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/23 21:20:42 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("FragTrap", 100, 100, 30) {
  std::cout << "Default Constructor from FragTrap was called." << std::endl;
  return;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30) {
  std::cout << "FragTrap know as " << name << " show up.";
  std::cout << std::endl;
  return;
}

FragTrap::FragTrap(FragTrap const &other) : ClapTrap(other) {
  *this = other;
  return;
}

FragTrap::~FragTrap(void) {
  std::cout << "Destructor from FragTrap called." << std::endl;
  return;
}

FragTrap &FragTrap::operator=(FragTrap const &other) {
  this->setName(other.getName());
  this->setAttack(other.getAttack());
  this->setHit(other.getHit());
  this->setEnergy(other.getEnergy());
  return *this;
}

void FragTrap::highFivesGuys(void) {
  std::cout << this->getName() << ": Do you wanna a highfive ?" << std::endl;
  return;
}

void FragTrap::attack(std::string const &target) {
  if (this->getHit() == 0) {
    this->deadObject("FragTrap");
  }
  if (this->getEnergy() == 0) {
    this->outOfEnergyWarning("FragTrap");
  }
  std::cout << "FragTrap " << this->getName();
  std::cout << " attacks " << target << ", with " << this->getAttack();
  std::cout << " points of damage!" << std::endl;
  this->setEnergy(this->getEnergy() - 1);
}
