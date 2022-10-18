/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:24:20 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/17 20:35:46 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <iostream>

int main ()
{
  uintptr_t raw;
  Data test(10);
  Data *dataPtr;

  std::cout << "Before any cast of Data: " << &test << '\n';
  raw = Data::serialize(&test);
  std::cout << "uintptr_t from function serialize: " << raw << '\n';
  dataPtr = Data::deserialize(raw);
  std::cout << "Pointer returned by deserialize function: " << dataPtr << '\n';
  if (dataPtr == &test) {
    std::cout << "The address returned by deserialize function "
              << "is equal to the original Object\n";
  } else {
    std::cout << "The address returned by deserialize function "
              << "isn't equal to the original Object\n";
  }
  return 0;
}
