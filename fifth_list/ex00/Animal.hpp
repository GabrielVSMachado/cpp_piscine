/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:12:56 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/26 22:29:10 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
public:
  Animal(void);
  Animal(Animal const &);
  Animal &operator=(Animal const &);
  virtual ~Animal(void);

  virtual void makeSound(void) const;
  virtual std::string getType(void) const;

protected:
  std::string type;
  Animal(std::string const &);
};

#endif // !ANIMAL_HPP
