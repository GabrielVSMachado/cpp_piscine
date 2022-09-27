/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:14:01 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/26 22:29:40 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : type("AnyAnimal") {
  std::cout << "Default constructor for class Animal!!!" << std::endl;
  return;
}

Animal::Animal(std::string const & type) : type(type) {
  std::cout << "Constructor called for Animal: " << type << std::endl;
  return;
}

Animal::Animal(Animal const &other) {
  *this = other;
  return;
}

Animal::~Animal(void) {
  std::cout << "Default destructor for class Animal!!!" << std::endl;
  return;
}

Animal &Animal::operator=(Animal const &other) {
  this->type = other.type;
  return *this;
}

void Animal::makeSound(void) const {
  std::cout << "Any sound possible for a Animal!!!" << std::endl;
  return;
}

std::string Animal::getType(void) const { return this->type; }
