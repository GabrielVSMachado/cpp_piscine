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

#include "Types.hpp"
#include <cctype>
#include <iostream>
#include <cmath>

int main (int argc, char *argv[])
{
  Types* types;

  if (argc != 2) {
    return 1;
  }

  try {
    types = new Types(argv[1]);
    std::cout << *types << std::endl;
  }
  catch (std::exception const &e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
  return 0;
}
