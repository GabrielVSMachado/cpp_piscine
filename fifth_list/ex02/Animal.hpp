/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:12:56 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/27 23:24:27 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "Brain.hpp"
#include <iostream>

class Animal {
public:
  virtual ~Animal(void);
  virtual void makeSound(void) const = 0;
  virtual std::string getType(void) const = 0;

protected:
  std::string type;
};

#endif // !ANIMAL_HPP
