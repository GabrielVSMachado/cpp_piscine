/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 01:11:04 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/23 21:22:47 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void) {
  FragTrap fragTrap = FragTrap("PennyWise");
  FragTrap stupid("StupidKid");

  fragTrap.highFivesGuys();
  std::cout << "Isn't a ballon ?" << std::endl;
  std::cout << "Do you wanna a ballon ?" << std::endl;
  std::cout << "Of course!" << std::endl;
  fragTrap.attack(stupid.getName());
  stupid.takeDamage(1000);
  return 0;
}
