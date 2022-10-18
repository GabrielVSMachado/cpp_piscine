/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 21:12:24 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/17 21:47:02 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>

static Base *generate() {
  srand(static_cast<unsigned int>(time(NULL)));
  switch (rand() % 3) {
    case 0:
      return new A();
    case 1:
      return new B();
    case 2:
      return new C();
  }
  return NULL;
}

static void identify(Base *p) {
  A *Atmp;
  B *Btmp;
  C *Ctmp;

  Atmp = dynamic_cast<A *>(p);
  if (Atmp) {
    std::cout << "The type of the object in the pointer is A\n";
    return;
  }

  Btmp = dynamic_cast<B *>(p);
  if (Btmp) {
    std::cout << "The type of the object in the pointer is B\n";
    return;
  }

  Ctmp = dynamic_cast<C *>(p);
  if (Ctmp) {
    std::cout << "The type of the object in the pointer is C\n";
    return;
  }
}

static void identify(Base& p) {
  try {
    A &Atmp = dynamic_cast<A &>(p);
    std::cout << "The type of the object in the reference is A\n\n";
    Atmp = static_cast<A>(Atmp);
    return;
  }
  catch (...) {}
  try {
    B &Btmp = dynamic_cast<B &>(p);
    std::cout << "The type of the object in the reference is B\n\n";
    Btmp = static_cast<B>(Btmp);
    return;
  }
  catch (...) {}
  try {
    C &Ctmp = dynamic_cast<C &>(p);
    std::cout << "The type of the object in the reference is C\n\n";
    Ctmp = static_cast<C>(Ctmp);
    return;
  }
  catch (...) {}
}

int main () {
  Base *ptr;

  for (int i = 0; i < 6; i++) {
    ptr = generate();
    identify(ptr);
    identify(*ptr);
    delete ptr;
    usleep(1e6);
  }
  return 0;
}
