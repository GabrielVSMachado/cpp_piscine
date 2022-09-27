/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:50:25 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/27 19:21:58 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"
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
    std::cout << std::endl;
  }
  {
    Animal **array;
    Dog dog;
    Dog *secondDog;

    array = new Animal *[10];

    for (size_t i = 0; i < 10; i++) {
      if (i < 5) {
        array[i] = new Dog();
      } else {
        array[i] = new Cat();
      }
    }

    dog.getBrain()->setNewIdea(0, "Gabriel");
    secondDog = new Dog(dog);

    std::cout << "dog first idea before: " << dog.getBrain()->getIdea(0)
              << std::endl;
    std::cout << "secondDog first idea before: "
              << secondDog->getBrain()->getIdea(0) << std::endl;

    secondDog->getBrain()->setNewIdea(0, "Vitor");

    std::cout << "dog first idea before: " << dog.getBrain()->getIdea(0)
              << std::endl;
    std::cout << "secondDog first idea before: "
              << secondDog->getBrain()->getIdea(0) << std::endl;

    delete secondDog;
    delete[] array;
  }
  return 0;
}
