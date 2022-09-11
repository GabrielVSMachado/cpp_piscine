/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 23:54:46 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/11 11:44:24 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon {
public:
  Weapon(void);
  ~Weapon(void);
  Weapon(std::string type);

  std::string const &getType(void) const;
  void setType(std::string newType);

private:
  std::string _type;
};

#endif // !WEAPON_HPP
