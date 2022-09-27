/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:50:25 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/26 22:34:46 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {
  {
    Animal const *meta = new Animal();
    Animal const *j = new Dog();
    Animal const *k = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << k->getType() << " " << std::endl;
    j->makeSound();
    k->makeSound();
    meta->makeSound();
    delete j;
    delete k;
    delete meta;
    std::cout << std::endl;
  }
  {
    WrongAnimal const *j = new WrongAnimal();
    WrongAnimal const *k = new WrongCat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << k->getType() << " " << std::endl;
    j->makeSound();
    k->makeSound();
    delete j;
    delete k;
  }
  return 0;
}
