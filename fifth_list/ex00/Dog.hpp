/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:31:02 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/26 22:38:09 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : virtual public Animal
{
public:
  Dog(void);
  Dog(Dog const &);
  Dog &operator=(Dog const &);
  virtual ~Dog(void);

  virtual void makeSound(void) const;
};

#endif // !DOG_HPP
