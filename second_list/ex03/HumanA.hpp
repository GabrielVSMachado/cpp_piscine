/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 10:36:29 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/11 11:39:14 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanA {
public:
  ~HumanA(void);
  HumanA(std::string name, Weapon &weapon);

  void attack(void) const;

private:
  Weapon &_weapon;
  std::string _name;
};

#endif // !HUMANA_HPP
