/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:21:31 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/26 22:33:02 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat(void) : Animal("Cat") {
  std::cout << "Default constructor for Cat called." << std::endl;
  return;
}

Cat::Cat(Cat const &other) : Animal(other) {
  std::cout << "Copy assignment constructor for Cat." << std::endl;
  return;
}

Cat::~Cat(void) {
  std::cout << "Destructor for Cat called." << std::endl;
  return;
}

Cat &Cat::operator=(Cat const &other) {
  this->type = other.type;
  return *this;
}

void Cat::makeSound(void) const {
  std::cout << "The Cat made miau!!!" << std::endl;
  return;
}

