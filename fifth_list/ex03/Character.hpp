/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 23:26:31 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/29 00:35:59 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
public:
  Character(void);
  Character(Character const &);
  Character(std::string const &);
  Character &operator=(Character const &);
  virtual ~Character(void);
  virtual std::string const &getName(void) const;
  virtual void equip(AMateria *);
  virtual void unequip(int);
  virtual void use(int, ICharacter &);

private:
  AMateria *_inventory[4];
  unsigned int _index;
  std::string _name;
};

#endif // !CHARACTER_HPP
