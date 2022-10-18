/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:12:11 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/17 20:39:00 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() {}

Data::Data(Data const &other) : _stupid(other._stupid) {}

Data& Data::operator=(Data const &other) {
  this->_stupid = other._stupid;
  return *this;
}

Data::Data(int const &stupidInt) : _stupid(stupidInt) {}

Data::~Data() {}

uintptr_t Data::serialize(Data *ptr) {
  return reinterpret_cast<uintptr_t>(ptr);
}

Data* Data::deserialize(uintptr_t raw) {
  return reinterpret_cast<Data *>(raw);
}

int const &Data::getStupidInt() const { return this->_stupid; }
