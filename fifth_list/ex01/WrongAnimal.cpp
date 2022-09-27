/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 21:37:10 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/26 22:37:47 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal") {
  std::cout << "Default constructor for WrongAnimal called." << std::endl;
  return;
}

WrongAnimal::WrongAnimal(WrongAnimal const &other) : type(other.type) {
  std::cout << "Copy assignment constructor called for WrongAnimal."
            << std::endl;
  return;
}

WrongAnimal::WrongAnimal(std::string const &type) : type(type) {
  std::cout << "Constructor for " << type << " called." << std::endl;
}

WrongAnimal::~WrongAnimal(void) {
  std::cout << "Destructor called for WrongAnimal." << std::endl;
  return;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &other) {
  this->type = other.type;
  return *this;
}

void WrongAnimal::makeSound(void) const {
  std::cout << "WrongAnimal make a sound." << std::endl;
  return;
}

std::string WrongAnimal::getType(void) const { return this->type; }
