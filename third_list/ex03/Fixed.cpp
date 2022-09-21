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
  return;
}

Fixed::Fixed(Fixed const &other) {
  this->_rawBits = other.getRawBits();
  return;
}

Fixed::Fixed(int const value) {
  this->_rawBits = value << Fixed::_fixedExponentRange;
  return;
}

Fixed::Fixed(float const value) {
  this->setRawBits(value);
}

Fixed::~Fixed(void) {
  return;
}

void Fixed::setRawBits(float const newValue) {
  this->_rawBits = roundf(newValue * std::pow(2, Fixed::_fixedExponentRange));
  return;
}

int Fixed::getRawBits(void) const { return this->_rawBits; }

std::ostream &operator<<(std::ostream &ostream, Fixed const &value) {
  ostream << value.toFloat();
  return ostream;
}

Fixed &Fixed::operator=(const Fixed &other) {
  this->_rawBits = other._rawBits;
  return *this;
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

Fixed Fixed::operator++(int) {
  Fixed tmp(*this);
  this->setRawBits(epsilon + this->toFloat());
  return tmp;
}

Fixed const &Fixed::operator++(void) {
  this->setRawBits(epsilon + this->toFloat());
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed tmp(*this);
  this->setRawBits(this->toFloat() - epsilon);
  return tmp;
}

Fixed const & Fixed::operator--(void) {
  this->setRawBits(this->toFloat() - epsilon);
  return *this;
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b) {
  return a < b ? a : b;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) { return a < b ? a : b; }

Fixed const &Fixed::max(Fixed const &a, Fixed const &b) {
  return a < b ? b : a;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) { return a < b ? b : a; }
