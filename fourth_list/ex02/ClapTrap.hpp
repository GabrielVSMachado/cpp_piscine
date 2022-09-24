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
  ClapTrap(std::string, unsigned int, unsigned int, unsigned int);
  ClapTrap &operator=(ClapTrap const &);
  ~ClapTrap(void);

  void attack(std::string const &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  void setHit(unsigned int);
  void setEnergy(unsigned int);
  void setAttack(unsigned int);
  void setName(std::string const &);
  unsigned int getHit(void) const;
  unsigned int getEnergy(void) const;
  unsigned int getAttack(void) const;
  std::string getName(void) const;

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
