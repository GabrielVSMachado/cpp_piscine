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

#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
  {
    ClapTrap test;

    for (unsigned int i = test.getEnergy(); 0 < test.getEnergy();
         test.setEnergy(--i)) {
      test.attack("Test 1");
    }
    test.attack("Test 2");
    std::cout << std::endl;
  }
  {
    ClapTrap test;

    while (test.getHit())
      test.takeDamage(2);
    test.attack("Test 2");
    std::cout << std::endl;
  }
  {
    ScavTrap theoden = ScavTrap("Théoden");
    ScavTrap uruk_hai("Uruk-hai");
    ScavTrap ork(uruk_hai);

    theoden.attack(uruk_hai.getName());
    uruk_hai.takeDamage(1);
    uruk_hai.attack(theoden.getName());
    theoden.takeDamage(14);
    uruk_hai.attack(theoden.getName());
    theoden.takeDamage(50);
    uruk_hai.attack(theoden.getName());
    theoden.takeDamage(20);
    std::cout << "Maybe wait Gandalf Arrive !!! ..." << std::endl;
    std::cout << "To the fortress !!!, said Théoden." << std::endl;
    theoden.guardGate();
    ScavTrap gandalf("Gandalf");
    gandalf.attack(uruk_hai.getName());
    uruk_hai.takeDamage(1000);
    std::cout << "Finally they won the war..." << std::endl;
    std::cout << std::endl;
  }
  {
    FragTrap pennyWise = FragTrap("Penny Wise");
    FragTrap stupid("Stupid Kid");

    pennyWise.highFivesGuys();
    std::cout << "Isn't a balloon ?" << std::endl;
    std::cout << "Do you wanna a baloon ?" << std::endl;
    std::cout << "Of course!" << std::endl;
    pennyWise.attack(stupid.getName());
    stupid.takeDamage(1000);
    std::cout << std::endl;
  }
  {
    DiamondTrap doctor("Dr. Frankstein");
    ScavTrap folks("folks");

    std::cout << "My name is: " << doctor.getName() << std::endl;
    std::cout << "ClapTrap name is: " << doctor.getClapTrapName();
    std::cout << std::endl;
    folks.attack(doctor.getName());
    doctor.highFivesGuys();
    std::cout << "Folks are too Scary!!!" << std::endl;
    folks.guardGate();
    std::cout << "Ups wrong name." << std::endl;
    doctor.setName("Frankstein");
    std::cout << "My name really is: " << doctor.getName() << std::endl;
    std::cout << "My ClapTrap name is: " << doctor.getClapTrapName();
    std::cout << std::endl;
    std::cout << "Hahaha!!!" << std::endl;
    doctor.attack(folks.getName());
    folks.takeDamage(1000);
  }
  return 0;
}
