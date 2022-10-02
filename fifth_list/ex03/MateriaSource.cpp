/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 00:25:32 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/02 01:29:29 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource(void) : _knowMaterias(), _howManyKnowMaterias(0) {
  std::cout << "MateriaSource's default constructor called." << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &other)
    : _knowMaterias(), _howManyKnowMaterias(0) {
  std::cout << "MateriaSource's copy assignment constructor called."
            << std::endl;
  *this = other;
}

MateriaSource::~MateriaSource(void) {
  std::cout << "MateriaSource's destructor called." << std::endl;
  for (unsigned int i = 0; i < this->_howManyKnowMaterias; i++) {
    delete this->_knowMaterias[i];
  }
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other) {
  for (unsigned int i = 0; i < this->_howManyKnowMaterias; i++) {
    delete this->_knowMaterias[i];
  }
  this->_howManyKnowMaterias = 0;
  for (unsigned int i = 0; i < other._howManyKnowMaterias; ++i) {
    this->_knowMaterias[i] = NULL;
    if (other._knowMaterias[i]) {
      this->_knowMaterias[i] = other._knowMaterias[i]->clone();
      ++this->_howManyKnowMaterias;
    }
  }
  return *this;
}

void MateriaSource::learnMateria(AMateria *newMateria) {
  if (this->_howManyKnowMaterias == 4) {
    return;
  }
  this->_knowMaterias[++this->_howManyKnowMaterias - 1] = newMateria;
}

AMateria *MateriaSource::createMateria(std::string const &type) {
  if (!this->_howManyKnowMaterias) {
    return NULL;
  }
  for (unsigned int i = this->_howManyKnowMaterias; i != 0;) {
    if (this->_knowMaterias[--i]->getType() == type)
      return this->_knowMaterias[i]->clone();
  }
  return 0;
}
