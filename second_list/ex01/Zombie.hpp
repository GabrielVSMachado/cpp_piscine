/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:06:37 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/10 22:30:48 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie
{
public:
  Zombie(void);
  ~Zombie(void);
  Zombie(std::string name);

  void announce(void) const;
  static Zombie* zombieHorde(int n, std::string name);
  Zombie& operator=(std::string name);

private:
  std::string _name;
};

