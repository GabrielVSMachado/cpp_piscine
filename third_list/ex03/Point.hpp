/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:48:02 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/19 20:27:29 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include "iostream"

class Point
{
public:
  Point(void);
  Point(const Point &);
  Point(float const x, float const y);
  Point &operator=(const Point &);
  ~Point(void);

  Fixed const &getXValue(void) const;
  Fixed const &getYValue(void) const;

private:
  Fixed const _x, _y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
std::ostream &operator<<(std::ostream &, Point const &);
#endif // !POINT_HPP
