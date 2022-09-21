/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 20:28:25 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/19 20:46:46 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <cmath>

static float triangleArea(
    Point const &p1, Point const &p2, Point const &p3) {
  float determinant;

  determinant = std::abs(
      p1.getXValue() * (p2.getYValue() - p3.getYValue())
      - p2.getXValue() * (p1.getYValue() - p3.getYValue())
      + p3.getXValue() * (p1.getYValue() - p2.getYValue())
      );
  return determinant / 2.0;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {

  float const AreaTotal = triangleArea(a, b, c);
  float const Area1 = triangleArea(point, b, c);
  float const Area2 = triangleArea(a, point, c);
  float const Area3 = triangleArea(a, b, point);

  return ((Area1 && Area2 && Area3) && (AreaTotal == Area1 + Area2 + Area3));
}
