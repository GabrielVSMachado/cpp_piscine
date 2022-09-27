/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:43:30 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/26 22:05:37 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog(void) : Animal("Dog") {
  std::cout << "Default Constructor for Dog called" << std::endl;
  return;
}

Dog::Dog(Dog const &other) : Animal(other) {
  std::cout << "Copy assignment operator for Dog called." << std::endl;
  return;
}

Dog::~Dog(void) {
  std::cout << "Destructor for Dog called." << std::endl;
  return;
}

Dog &Dog::operator=(Dog const &other) {
  this->type = other.type;
  return *this;
}

void Dog::makeSound(void) const {
  std::cout << "Dog do:  whoof whoof." << std::endl;
  return;
}
