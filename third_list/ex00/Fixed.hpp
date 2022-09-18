/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 14:08:36 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/18 14:08:39 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
public:
  Fixed(void);
  Fixed(Fixed const &);
  Fixed &operator=(Fixed const &);
  ~Fixed(void);

  int getRawBits(void) const;
  void setRawBits(int const raw);


private:
  int _fixedPoint;
  static int const _fractionalBits;
};

#endif // !FIXED_HPP
