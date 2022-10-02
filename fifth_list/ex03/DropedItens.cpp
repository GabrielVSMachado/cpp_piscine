/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DropedItens.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 23:50:17 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/02 00:02:31 by gvitor-s         ###   ########.fr       */
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
  DropedItens::Node::clone(this->_head, other._head);
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

void DropedItens::Node::clone(Node *&to, Node const *from) {
  DropedItens::Node* tmpNode;

  while (from)
  {
    tmpNode = new DropedItens::Node(from->content->clone());
    tmpNode->next = to;
    to = tmpNode;
    from = from->next;
  }
}
