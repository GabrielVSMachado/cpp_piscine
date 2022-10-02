/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 22:27:10 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/29 12:33:54 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
public:
  Ice(void);
  Ice(Ice const &);
  Ice &operator=(Ice const &);
  virtual ~Ice(void);
  virtual AMateria *clone(void) const;
  virtual void use(ICharacter &);
};

#endif // !ICE_HPP
