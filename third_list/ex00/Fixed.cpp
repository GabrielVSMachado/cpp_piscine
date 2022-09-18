/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:07:43 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/15 16:12:46 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int const Fixed::_fractionalBits = 8;

Fixed::Fixed(void): _fixedPoint(0) {
  std::cout << "Default constructor called" << std::endl;
  return;
}

Fixed::~Fixed(void) {
  std::cout << "Destructor called" << std::endl;
  return;
}

Fixed::Fixed(Fixed const &other) {
  std::cout << "Copy constructor called" << std::endl;
  *this = other;
}

Fixed &Fixed::operator=(Fixed const &other) {
  std::cout << "Copy assigment operator called" << std::endl;
  this->_fixedPoint = other._fixedPoint;
  return *this;
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return this->_fixedPoint;
}

void Fixed::setRawBits(int const raw) {
  this->_fixedPoint = raw;
}
