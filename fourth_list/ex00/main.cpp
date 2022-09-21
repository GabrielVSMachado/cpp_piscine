/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 01:11:04 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/21 01:30:19 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
  ClapTrap starks("Stark's");
  ClapTrap johnSnow(starks);
  ClapTrap Lannisters("Lannister's");

  Lannisters.attack("Stark's");
  starks.takeDamage(1);
  Lannisters.attack("Stark's");
  starks.takeDamage(5);
  starks.beRepaired(2);
  Lannisters.attack("Stark's");
  starks.takeDamage(6);
  starks.beRepaired(1);
  std::cout << "See you on next season." << std::endl;
  return 0;
}
