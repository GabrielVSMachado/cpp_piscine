/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 21:11:44 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/26 22:29:23 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
public:
  WrongAnimal(void);
  WrongAnimal(WrongAnimal const &);
  WrongAnimal &operator=(WrongAnimal const &);
  virtual ~WrongAnimal(void);

  virtual std::string getType(void) const;
  void makeSound(void) const;

protected:
  std::string type;
  WrongAnimal(std::string const &);
};

#endif // !WRONGANIMAL_HPP
