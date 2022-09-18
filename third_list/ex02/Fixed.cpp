/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 14:10:11 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/18 15:31:08 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>

int const Fixed::_fixedExponentRange = 8;

Fixed::Fixed(void) : _rawBits(0) {
  std::cout << "Default constructor called" << std::endl;
  return;
}

Fixed::Fixed(Fixed const &other) {
  std::cout << "Copy assignment constructor called" << std::endl;
  this->_rawBits = other.getRawBits();
  return;
}

Fixed::Fixed(int const value) {
  std::cout << "Int constructor called" << std::endl;
  this->_rawBits = value << Fixed::_fixedExponentRange;
  return;
}

Fixed::Fixed(float const value) {
  std::cout << "Float constructor called" << std::endl;
  this->_rawBits = roundf(value * std::pow(2, Fixed::_fixedExponentRange));
}

Fixed::~Fixed(void) {
  std::cout << "Destructor called" << std::endl;
  return;
}

std::ostream &operator<<(std::ostream &ostream, Fixed const &value) {
  ostream << value.toFloat();
  return ostream;
}

Fixed &Fixed::operator=(const Fixed &other) {
  this->_rawBits = other._rawBits;
  return *this;
}

int Fixed::getRawBits(void) const { return this->_rawBits; }

void Fixed::setRawBits(const int newValue) {
  this->_rawBits = newValue;
  return;
}

float Fixed::toFloat(void) const {
  return (float)this->_rawBits / std::pow(2, Fixed::_fixedExponentRange);
}

int Fixed::toInt(void) const {
  return this->_rawBits >> Fixed::_fixedExponentRange;
}

float Fixed::operator+(Fixed const &other) const {
  return this->toFloat() + other.toFloat();
}

float Fixed::operator-(Fixed const &other) const {
  return this->toFloat() - other.toFloat();
}

float Fixed::operator*(Fixed const &other) const {
  return this->toFloat() * other.toFloat();
}

float Fixed::operator/(Fixed const &other) const {
  return this->toFloat() / other.toFloat();
}

bool Fixed::operator<(Fixed const &other) const {
  return this->toFloat() < other.toFloat();
}

bool Fixed::operator>(Fixed const &other) const {
  return this->toFloat() > other.toFloat();
}

bool Fixed::operator==(Fixed const &other) const {
  return std::abs(this->toFloat() - other.toFloat()) < 0.00001;
}

bool Fixed::operator!=(Fixed const &other) const { return !(*this == other); }

bool Fixed::operator>=(Fixed const &other) const {
  return *this > other || *this == other;
}

bool Fixed::operator<=(Fixed const &other) const {
  return *this < other || *this == other;
}
