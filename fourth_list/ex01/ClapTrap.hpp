/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 00:24:01 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/21 01:30:35 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
public:
  ClapTrap(void);
  ClapTrap(ClapTrap const &);
  ClapTrap(std::string name);
  ClapTrap &operator=(ClapTrap const &);
  ~ClapTrap(void);

  void attack(std::string const &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

protected:
  void deadObject(std::string const & type) const;
  void outOfEnergyWarning(std::string const & type) const;

private:
  unsigned int _hit;
  unsigned int _energy;
  unsigned int _attack;
  std::string _name;
};

#endif // !CLAPTRAP_HPP
