/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 09:52:41 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/02 01:29:29 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Cure.hpp"
#include "DropedItens.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main(void) {
  {
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter *me = new Character("me");

    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);


    ICharacter *bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
    std::cout << std::endl;
  }
  {
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter *me = new Character("me");

    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    me->unequip(1);


    ICharacter *bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
    std::cout << std::endl;
  }
  {
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter *me = new Character("me");

    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    me->unequip(1);
    src->learnMateria(new Ice());
    me->equip(src->createMateria("cure"));


    ICharacter *bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
    std::cout << std::endl;
  }
  {
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter *me = new Character("me");

    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    src->learnMateria(new Ice());
    me->equip(src->createMateria("cure"));
    me->equip(src->createMateria("ice"));
    me->unequip(0);
    me->unequip(1);
    me->unequip(2);
    me->unequip(3);
    me->unequip(10000);

    ICharacter *bob = new Character("bob");
    me->use(10000, *bob);

    delete bob;
    delete me;
    delete src;
    std::cout << std::endl;
  }
  return 0;
}
