/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:19:24 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/02 01:19:54 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "DropedItens.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
public:
  MateriaSource(void);
  MateriaSource(MateriaSource const &);
  MateriaSource &operator=(MateriaSource const &);
  virtual ~MateriaSource(void);

  void learnMateria(AMateria *);
  AMateria *createMateria(std::string const &);

private:
  AMateria *_knowMaterias[4];
  unsigned int _howManyKnowMaterias;
};

#endif // !MATERIASOURCE_HPP
