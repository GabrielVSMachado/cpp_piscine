/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 22:59:28 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/29 12:34:04 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
public:
  Cure(void);
  Cure(Cure const &);
  Cure &operator=(Cure const &);
  virtual ~Cure(void);
  virtual AMateria* clone(void) const;
  virtual void use(ICharacter &);
};

#endif // !CURE_HPP
