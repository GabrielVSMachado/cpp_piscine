/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:52:28 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/27 19:20:44 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <string>

Brain::Brain(void) {
  std::cout << "Brain's default constructor called." << std::endl;
  return;
}

Brain::Brain(Brain const &other) {
  std::cout << "Brain's copy assignment constructor called." << std::endl;
  *this = other;
  return;
}

Brain::~Brain(void) {
  std::cout << "Brain's destructor called." << std::endl;
  return;
}

Brain &Brain::operator=(Brain const &other) {
  for (size_t i = 0; i < other._ideas->length(); ++i) {
    this->_ideas[i] = other._ideas[i];
  }
  return *this;
}

void Brain::setNewIdea(int index, std::string const &newIdea) {
  if (index > 99 || index < 0) {
    return;
  }
  this->_ideas[index] = newIdea;
}

std::string Brain::getIdea(int index) const {
  if (index < 0 || index > 99) {
    return "";
  }
  return this->_ideas[index];
}
