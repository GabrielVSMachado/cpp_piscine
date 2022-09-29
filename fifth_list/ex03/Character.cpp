/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 23:33:53 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/29 00:36:00 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character(void) : _inventory(), _inventory_size(0), _name("NPC") {
  std::cout << "Character's default constructor called." << std::endl;
  for (unsigned int i = 0; i < 4; ++i) {
    this->_inventory[i] = NULL;
  }
  return;
}

Character::Character(Character const &other) {
  std::cout << "Character's copy assignment constructor called." << std::endl;
  *this = other;
  return;
}

Character::Character(std::string const &name)
    : _inventory_size(0), _name(name) {
  std::cout << "Character's constructor with std::string parameter called."
            << std::endl;
  for (unsigned int i = 0; i < 4; ++i) {
    this->_inventory[i] = NULL;
  }
  return;
}

Character::~Character(void) {
  std::cout << "Character's destructor called." << std::endl;
  return;
}

Character &Character::operator=(Character const &other) {
  while (this->_inventory_size)
    delete this->_inventory[--this->_inventory_size];
  for (unsigned int i = 0; i < other._inventory_size; ++i) {
    this->_inventory[i] = other._inventory[i]->clone();
  }
  return *this;
}

void Character::equip(AMateria *m) {
  if (this->_inventory_size == 4) {
    return;
  }
  this->_inventory[this->_inventory_size] = m;
  ++this->_inventory_size;
}

// BUG: _inventory order is not garranty when a item in the middle is unequip
void Character::unequip(int item) {
  if (item > 3 || item < 0) {
    return;
  }
  this->_inventory[item] = NULL;
  --this->_inventory_size;
}

void Character::use(int index, ICharacter &target) {
  if (index < 0 || index > 3) {
    return;
  }
  return this->_inventory[index]->use(target);
}

std::string const &Character::getName(void) const { return this->_name; }
