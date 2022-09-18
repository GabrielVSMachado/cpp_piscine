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

class Fixed {
public:
  Fixed(void);
  Fixed(Fixed const &);
  Fixed(int const);
  Fixed(float const);
  Fixed& operator=(Fixed const &);
  ~Fixed(void);

  int getRawBits(void) const;
  void setRawBits(int const newValue);
  float toFloat(void) const;
  int toInt(void) const;

private:
  int _rawBits;
  static int const _fixedExponentRange;
};

std::ostream& operator<<(std::ostream&, Fixed const &);
#endif // !FIXED_HPP
