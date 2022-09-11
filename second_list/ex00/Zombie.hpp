/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:06:37 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/10 21:30:55 by gvitor-s         ###   ########.fr       */
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
  static Zombie* newZombie(std::string name);
  static void randomChump(std::string name);

private:
  std::string _name;
};

