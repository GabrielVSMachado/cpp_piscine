/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:20:28 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/27 18:38:39 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : virtual public Animal {
public:
  Cat(void);
  Cat(Cat const &);
  Cat &operator=(Cat const &);
  virtual ~Cat(void);

  virtual void makeSound(void) const;
  Brain* getBrain(void);

private:
  Brain* _brain;
};

#endif // !CAT_HPP
