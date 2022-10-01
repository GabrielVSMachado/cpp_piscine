/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DropedItens.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 00:28:55 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/01 02:14:27 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DropedItens.hpp"
#include <iostream>

DropedItens::DropedItens(void) : _head(NULL) {
  std::cout << "DropedItens's default constructor called." << std::endl;
}

DropedItens::DropedItens(DropedItens const &other) : _head(NULL) {
  *this = other;
}

DropedItens::~DropedItens(void) {
  std::cout << "DropedItens's destructor called." << std::endl;
  delete this->_head;
}

DropedItens &DropedItens::operator=(DropedItens const &other) {
  delete this->_head;
  this->_head = NULL;
  *this->_head = other._head;
  return *this;
}

void DropedItens::add(AMateria const *newAMateria) {
  DropedItens::Node *tmp = new DropedItens::Node(newAMateria);
  tmp->next = this->_head;
  this->_head = tmp;
}

DropedItens::Node::Node(AMateria const *newAMateria)
    : content(newAMateria), next(NULL) {}

DropedItens::Node::~Node(void) {
  std::cout << "Node's destructor called." << std::endl;
  delete this->content;
  delete this->next;
}

DropedItens::Node &
DropedItens::Node::operator=(DropedItens::Node const *other) {
  DropedItens::Node *tmp = NULL;
  if (!other) {
    return *tmp;
  }
  tmp = new DropedItens::Node(other->content->clone());
  *tmp->next = other->next;
  return *tmp;
}
