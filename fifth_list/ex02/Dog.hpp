/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:31:02 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/27 18:39:46 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : virtual public Animal {
public:
  Dog(void);
  Dog(Dog const &);
  Dog &operator=(Dog const &);
  virtual ~Dog(void);

  Brain *getBrain(void);
  virtual void makeSound(void) const;
  virtual std::string getType(void) const;

private:
  Brain *_brain;
};

#endif // !DOG_HPP
