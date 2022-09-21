/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:48:18 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/19 20:27:59 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"
#include <ostream>

Point::~Point(void) { return; }
Point::Point(void) : _x(Fixed()), _y(Fixed()) { return; }
Point::Point(Point const &other) : _x(other._x), _y(other._y) { return; }
Point::Point(float const x, float const y) : _x(Fixed(x)), _y(Fixed(y)) {
  return;
}

Fixed const &Point::getXValue(void) const { return this->_x; }

Fixed const &Point::getYValue(void) const { return this->_y; }

std::ostream &operator<<(std::ostream &o, Point const &p) {
  o << "Point(" << p.getXValue() << ", " << p.getYValue() << ")";
  return o;
}
