/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:21:31 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/27 18:39:23 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Animal.hpp"
#include "Brain.hpp"

Cat::Cat(void) : Animal("Cat"), _brain(new Brain()) {
  std::cout << "Default constructor for Cat called." << std::endl;
  return;
}

Cat::Cat(Cat const &other)
    : Animal(other), _brain(new Brain(*other._brain)) {
  std::cout << "Copy assignment constructor for Cat." << std::endl;
  return;
}

Cat::~Cat(void) {
  std::cout << "Destructor for Cat called." << std::endl;
  delete this->_brain;
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

Brain *Cat::getBrain(void) { return this->_brain; }
