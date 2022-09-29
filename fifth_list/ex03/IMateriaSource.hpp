/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:50:26 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/29 17:56:02 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "AMateria.hpp"
class IMateriaSource
{
public:
  virtual ~IMateriaSource(void) {};
  virtual void learnMateria(AMateria *) = 0;
  virtual AMateria *createMateria(std::string const &) = 0;
};

#endif // !IMATERIASOURCE_HPP
