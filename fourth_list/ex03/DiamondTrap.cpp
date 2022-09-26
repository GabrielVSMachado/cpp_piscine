/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:32:28 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/26 14:13:19 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap(void)
    : ClapTrap("DiamondTrap_clap_trap", 100, 50, 30), _name("DiamondTrap") {
  std::cout << "Default Construct for DiamondTrap called." << std::endl;
  return;
}

DiamondTrap::DiamondTrap(DiamondTrap const &other) : ClapTrap(other) {
  std::cout << "Copy assignment constructor called." << std::endl;
  *this = other;
  return;
}

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_trap", 100, 50, 30), _name(name) {
  std::cout << "DiamondTrap: " << name << " it's alive!!!" << std::endl;
}

DiamondTrap::~DiamondTrap(void) {
  std::cout << "Destructor for " << this->_name << " called." << std::endl;
  return;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &other) {
  this->_name = other._name;
  return *this;
}

void DiamondTrap::attack(std::string const &target) {
  return ScavTrap::attack(target);
}

std::string DiamondTrap::getName(void) const { return this->_name; }
void DiamondTrap::setName(std::string const &newName) {
  this->_name = newName;
  this->setClapTrapName(newName + "_clap_trap");
  return;
}

std::string DiamondTrap::getClapTrapName(void) const {
  return ClapTrap::getName();
}

void DiamondTrap::setClapTrapName(std::string const &newClapTrapName) {
  return ClapTrap::setName(newClapTrapName);
}
