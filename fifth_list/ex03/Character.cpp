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
#include <cstddef>
#include <iostream>

Character::Character(void) : _inventory(), _index(0), _name("NPC") {
  std::cout << "Character's default constructor called." << std::endl;
  return;
}

Character::Character(Character const &other) {
  std::cout << "Character's copy assignment constructor called." << std::endl;
  *this = other;
  return;
}

Character::~Character(void) {
  std::cout << "Character's destructor called." << std::endl;
  return;
}

Character &Character::operator=(Character const &other) {
  while (this->_index)
    delete this->_inventory[--this->_index];
  for (unsigned int i = 0; i < other._index; i++) {
    this->_inventory[i] = other._inventory[i]->clone();
  }
  return *this;
}

void Character::equip(AMateria *m) {
  if (this->_index == 4) {
    return;
  }
  this->_inventory[this->_index++] = m;
}

std::string const &Character::getName(void) const { return this->_name; }

