/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 11:25:22 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/11 11:39:41 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanB {
public:
  HumanB(std::string name);
  ~HumanB(void);

  void setWeapon(Weapon& weapon);
  void attack(void) const;

private:
  Weapon* _weapon;
  std::string _name;
};

#endif // !HUMANB_HPP
