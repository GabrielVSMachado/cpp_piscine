/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:30:30 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/29 12:31:44 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <string>
class AMateria;

class ICharacter {
public:
  virtual ~ICharacter(void){};
  virtual std::string const &getName(void) const = 0;
  virtual void equip(AMateria *) = 0;
  virtual void unequip(int) = 0;
  virtual void use(int, ICharacter &) = 0;
};


#endif // !ICHARACTER_HPP
