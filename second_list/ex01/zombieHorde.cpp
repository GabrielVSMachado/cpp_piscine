/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:05:26 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/10 22:47:43 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* Zombie::zombieHorde(int n, std::string commonName) {
  Zombie* horde = new Zombie[n];

  for (int i = 0; i < n; i++) {
    horde[i] = commonName;
  }
  return horde;
}
