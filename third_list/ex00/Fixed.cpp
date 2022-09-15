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

Fixed::Fixed(void) { return; }
Fixed::~Fixed(void) { return; }

Fixed::Fixed(Fixed const &other) {
  *this = other;
}

Fixed& Fixed::operator=(Fixed const &other) {
  return *this;
}
