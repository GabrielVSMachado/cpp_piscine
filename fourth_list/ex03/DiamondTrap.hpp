/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:32:34 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/26 14:07:17 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

class DiamondTrap : public ScavTrap, public FragTrap {
public:
  DiamondTrap(void);
  DiamondTrap(std::string);
  DiamondTrap(DiamondTrap const &);
  DiamondTrap &operator=(DiamondTrap const &);
  ~DiamondTrap(void);

  void attack(std::string const &);
  std::string getName(void) const;
  void setName(std::string const &);
  std::string getClapTrapName(void) const;

private:
  std::string _name;
  void setClapTrapName(std::string const &);
};

#endif // !DIAMONDTRAP_HPP
