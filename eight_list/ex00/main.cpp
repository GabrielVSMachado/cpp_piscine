/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 23:26:27 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/18 23:27:40 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include "whatever.hpp"

int main ()
{
  int a = 2, b = 3;

  ::swap(a, b);
  std::cout << "a = " << a << ", b = " << b << '\n';
  std::cout << "min( a, b ) = " << ::min<int>(a, b) << '\n';
  std::cout << "max( a, b ) = " << ::max<int>(a, b) << '\n';

  std::string c = "chaine1", d = "chaine2";

  ::swap(c, d);
  std::cout << "c = " << c << ", d = " << d << '\n';
  std::cout << "min( c, d ) = " << ::min<std::string>(c, d) << '\n';
  std::cout << "max( c, d ) = " << ::max<std::string>(c, d) << '\n';
  return 0;
}
