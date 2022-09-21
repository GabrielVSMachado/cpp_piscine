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
#include "Point.hpp"
#include <iostream>

int main(void) {
  Point const p[][4] = {
    {Point(0, 2), Point(0, 2), Point(0, -2), Point(0, 1)},
    {Point(3, 3), Point(0, 0), Point(-3, 3), Point(0.2, 1)},
    {Point(0, 0), Point(10, 30), Point(20, 0), Point(10, 15)}
  };

  bool const results[3] = {
    bsp(p[0][0], p[0][1], p[0][2], p[0][3]),
    bsp(p[1][0], p[1][1], p[1][2], p[1][3]),
    bsp(p[2][0], p[2][1], p[2][2], p[2][3])
  };

  for (int i = 0; i < 3; i++) {
    if (results[i]) {
      std::cout <<  p[i][3] << " is inside." << std::endl;
    } else {
      std::cout << p[i][3] << " not inside." << std::endl;
    }
  }
  return 0;
}
