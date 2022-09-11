/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:45:16 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/10 22:46:48 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "Zombie.hpp"

int main (int argc, char *argv[])
{
  int number;
  Zombie* horde;

  if (argc != 2)
    return 1;

  number = std::atoi(argv[1]);

  if (number < 0)
    return 1;

  horde = Zombie::zombieHorde(number, "Foo");

  for (int i = 0; i < number; i++) {
    horde[i].announce();
  }

  delete [] horde;
  return 0;
}
