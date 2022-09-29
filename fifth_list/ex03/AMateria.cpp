/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 22:04:36 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/28 22:08:40 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(std::string const &type) : type(type) {
  std::cout << "AMateria's default constructor called." << std::endl;
  return;
}

AMateria::~AMateria(void) {
  std::cout << "AMateria's default destructor called." << std::endl;
  return;
}

void AMateria::use(ICharacter &target) {
  if (this->type == "ice") {
    std::cout << "* shoots an ice bolt at " << target.getName();
    std::cout << " *" << std::endl;
    return;
  } else {
    std::cout << "* heals " << target.getName();
    std::cout << "'s wounds *" << std::endl;
  }
}

std::string const &AMateria::getType(void) const { return this->type; }
