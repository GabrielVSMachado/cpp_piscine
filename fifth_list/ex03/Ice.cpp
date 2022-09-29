/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 22:29:02 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/28 23:20:40 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "AMateria.hpp"
#include <iostream>

Ice::Ice(void) : AMateria("ice") {
  std::cout << "Ice's default constructor called" << std::endl;
  return;
}

Ice::Ice(Ice const &other) : AMateria(other.getType()) {
  std::cout << "Ice's copy assignment constructor called." << std::endl;
  return;
}

Ice::~Ice(void) {
  std::cout << "Ice's destructor called." << std::endl;
  return;
}

Ice &Ice::operator=(Ice const &other) {
  this->type = other.type;
  return *this;
}

AMateria *Ice::clone(void) const { return new Ice(); }
