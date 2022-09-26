/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 01:40:52 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/26 14:07:48 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap {
public:
  ScavTrap(void);
  ScavTrap(ScavTrap const &);
  ScavTrap(std::string name);
  ScavTrap &operator=(ScavTrap const &);
  ~ScavTrap(void);

  void guardGate(void);
  void attack(std::string const & target);
};

#endif // !SCAVTRAP_HPP
