/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 14:55:29 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/18 15:21:47 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void) {
  Fixed a;
  Fixed const b(Fixed(5.05f) * Fixed(2));
  Fixed const c(42);

  std::cout << "a: " << a << std::endl;
  std::cout << "a: " << ++a << std::endl;
  std::cout << "a: " << a++ << std::endl;
  std::cout << "a: " << a << std::endl;
  std::cout << "a: " << --a << std::endl;
  std::cout << "a: " <<  a-- << std::endl;
  std::cout << "a: " <<  a << std::endl;

  std::cout << "a is equal to b: " << (a == b ? "true" : "false") << std::endl;
  std::cout << "a is different to b: " << (a != b ? "true" : "false");
  std::cout << std::endl;
  std::cout << "a is greater than b: " << (a > b ? "true" : "false");
  std::cout << std::endl;
  std::cout << "a is greater than or equal to b: ";
  std::cout << (a >= b ? "true" : "false") << std::endl;
  std::cout << "a is lesser than b: " << (a < b ? "true" : "false");
  std::cout << std::endl;
  std::cout << "a is lesser than or equal to b: ";
  std::cout << (a <= b ? "true" : "false") << std::endl;

  std::cout << "a + b: " << a + b << std::endl;
  std::cout << "a - b: " << a - b << std::endl;
  std::cout << "a * b: " << a * b << std::endl;
  std::cout << "a / b: " << a / b << std::endl;

  std::cout << "b: " << b << std::endl;
  std::cout << "c: " << c << std::endl;

  std::cout << "max: " << Fixed::max(a, b) << std::endl;
  std::cout << "min: " << Fixed::min(a, b) << std::endl;
  std::cout << "const max: " << Fixed::max(c, b) << std::endl;
  std::cout << "const min: " << Fixed::min(c, b) << std::endl;

  return 0;
}
