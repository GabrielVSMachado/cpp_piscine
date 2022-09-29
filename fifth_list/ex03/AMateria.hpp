/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 22:02:06 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/29 12:32:47 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"

class AMateria {
public:
  AMateria(std::string const &);
  virtual ~AMateria(void);
  AMateria& operator=(AMateria const &);

  std::string const &getType(void) const;
  virtual AMateria *clone(void) const = 0;
  virtual void use(ICharacter &);

protected:
  std::string type;
};

#endif // !AMATERIA_HPP
