/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:28:01 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/10 21:36:26 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main (void)
{
  Zombie* zombieCretedInHeap = Zombie::newZombie("Foo");

  zombieCretedInHeap->announce();
  Zombie::randomChump("Bar");

  delete zombieCretedInHeap;
  return 0;
}
