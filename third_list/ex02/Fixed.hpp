/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 14:10:00 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/18 15:20:06 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

#define epsilon std::pow(2, -8)

class Fixed {
public:
  Fixed(void);
  Fixed(Fixed const &);
  Fixed(int const);
  Fixed(float const);
  ~Fixed(void);


  Fixed &operator=(Fixed const &);
  float operator+(Fixed const &) const;
  float operator-(Fixed const &) const;
  float operator*(Fixed const &) const;
  float operator/(Fixed const &) const;
  bool operator<(Fixed const &) const;
  bool operator>(Fixed const &) const;
  bool operator>=(Fixed const &) const;
  bool operator<=(Fixed const &) const;
  bool operator==(Fixed const &) const;
  bool operator!=(Fixed const &) const;
  Fixed operator++(int);
  Fixed const & operator++(void);
  Fixed operator--(int);
  Fixed const & operator--(void);

  int getRawBits(void) const;
  void setRawBits(float const newValue);
  float toFloat(void) const;
  int toInt(void) const;

  static Fixed const & min(Fixed const &, Fixed const &);
  static Fixed& min(Fixed&, Fixed &);
  static Fixed const & max(Fixed const &, Fixed const &);
  static Fixed& max(Fixed&, Fixed&);

private:
  int _rawBits;
  static int const _fixedExponentRange;
};

std::ostream &operator<<(std::ostream &, Fixed const &);
#endif // !FIXED_HPP
