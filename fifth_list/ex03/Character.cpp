/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 23:33:53 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/02 00:13:18 by gvitor-s         ###   ########.fr       */
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
    : _inventory(), _inventory_size(0), _name(name) {
  std::cout << "Character's constructor with std::string parameter called."
            << std::endl;
  return;
}

Character::~Character(void) {
  std::cout << "Character's destructor called." << std::endl;
  while (this->_inventory_size)
    delete this->_inventory[--this->_inventory_size];
  return;
}

Character &Character::operator=(Character const &other) {
  this->_name = other._name;
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

void Character::unequip(int item) {
  if (item > 3 || item < 0 || !this->_inventory_size ||
      (unsigned int)item > this->_inventory_size - 1) {
    return;
  }

  this->_dropedItens.add(this->_inventory[item]);
  this->_inventory[item] = NULL;
  if ((unsigned int)item != this->_inventory_size - 1) {
    for (unsigned int i = item + 1; i < 4; ++i) {
      this->_inventory[i - 1] = this->_inventory[i];
    }
  }
  --this->_inventory_size;
}

void Character::use(int index, ICharacter &target) {
  if (index < 0 || (unsigned int)index > this->_inventory_size - 1) {
    return;
  }
  return this->_inventory[index]->use(target);
}

std::string const &Character::getName(void) const { return this->_name; }
