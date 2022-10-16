/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:23:11 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/15 14:28:54 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <cstdlib>
#include <iostream>

int main (int argc, char *argv[])
{
  if (argc != 2) {
    return 1;
  }
  char c = argv[1][0];
  double test = static_cast<double>(c);
  int i = static_cast<int>(c);
  float f = static_cast<float>(c);
  std::cout << "Double: " << static_cast<double>(test) << std::endl;
  if (std::isprint(c)) {
    std::cout << "Char: " << c << std::endl;
  }
  else {
    std::cout << "Char: Non displayable." << std::endl;
  }
  std::cout << "Int: " << i << std::endl;
  std::cout << "Float: " << f << 'f' << std::endl;
  return 0;
}
