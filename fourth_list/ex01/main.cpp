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

#include "ScavTrap.hpp"

int main(void) {
	ScavTrap theoden = ScavTrap("Théoden");
	ScavTrap uruk_hai("Uruk-hai");

	theoden.attack(uruk_hai.getName());
	uruk_hai.takeDamage(1);
	uruk_hai.attack(theoden.getName());
	theoden.takeDamage(25);
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
	return 0;
}
