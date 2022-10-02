/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 23:01:41 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/28 23:23:35 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

Cure::Cure(void) : AMateria("cure") {
  std::cout << "Cure's default constructor called" << std::endl;
  return;
}

Cure::Cure(Cure const &other) : AMateria(other.getType()) {
  std::cout << "Cure's copy assignment constructor called." << std::endl;
  return;
}

Cure::~Cure(void) {
  std::cout << "Cure's destructor called." << std::endl;
  return;
}

Cure &Cure::operator=(Cure const &other) {
  this->type = other.type;
  return *this;
}

void Cure::use(ICharacter &target) {
  std::cout << "* heals " << target.getName();
  std::cout << "'s wounds *" << std::endl;
}

AMateria *Cure::clone(void) const { return new Cure(); }
