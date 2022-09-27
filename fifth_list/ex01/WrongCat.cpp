/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 21:48:58 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/26 22:37:49 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
  std::cout << "Default constructor for WrongCat called." << std::endl;
  return;
}

WrongCat::WrongCat(WrongCat const &other) : WrongAnimal(other) {
  std::cout << "Copy assignment constructor for WrongCat called." << std::endl;
  return;
}

WrongCat::~WrongCat(void) {
  std::cout << "Destructor for WrongCat called." << std::endl;
  return;
}

WrongCat& WrongCat::operator=(WrongCat const &other) {
  this->type = other.type;
  return *this;
}

void WrongCat::makeSound(void) const {
  std::cout << "WrongCat do: whoof whoof!!!" << std::endl;
  return;
}
