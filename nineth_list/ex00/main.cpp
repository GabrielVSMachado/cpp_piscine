/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 12:05:44 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/23 13:49:07 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <cstdlib>
#include <vector>
#include <list>
#include <ctime>
#include <iostream>


int main ()
{
  {
    std::vector<int> vector;
    int* tmp;
    srand(time(NULL));

    for (int i = 0; i < 20; i++) {
      vector.push_back(rand() % 43);
    }

    try {
      tmp = &easyfind(vector, 42);
      std::cout << "I found: " << *tmp << " in vector !\n";
    }
    catch (const NotFoundException&e) {
      std::cerr << e.what() << '\n';
    }
  }
  {
    int* tmp;
    srand(time(NULL));
    std::list<int> list;

    for (int i = 0; i < 10; i++) {
      list.push_back(rand() % 43);
    }

    try {
      tmp = &easyfind(list, 42);
      std::cout << "I found: " << *tmp << " in list !\n";
    }
    catch (const NotFoundException&e) {
      std::cerr << e.what() << '\n';
    }

  }
  return 0;
}
