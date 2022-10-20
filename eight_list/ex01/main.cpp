/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:58:57 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/20 17:54:18 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>


template<typename T>
void pow2(T &num) { num = num * num; }

template<>
void pow2<std::string>(std::string &word);

template<typename T>
T const &print(T const &t) {
  std::cout << t << ' ';
  return t;
}

std::string * change_a_to_b(std::string &word) {
  for (size_t i = word.find('a'); i != std::string::npos; i = word.find('a')) {
    word[i] = 'b';
  }
  return &word;
}

int main ()
{
  int numbers[] = {1, 2, 3, 4, 5, 6};

  iter<int, void (*)(int &)>(numbers, 6, pow2<int>);
  std::cout << "Test Pow2<int> ";
  iter<int, int const &(*)(int const &)>(numbers, 6, print<int>);
  std::cout << '\n';

  float numbersf[] = {42.42, 43.43, 44.44};
  iter<float, void (*)(float &)>(numbersf, 3, pow2<float>);
  std::cout << "Test Pow2<float> ";
  iter<float, float const &(*)(float const &)>(numbersf, 3, print<float>);
  std::cout << '\n';

  std::string generic[] = {"aaaaaaaaa", "gabriel", "vitor"};
  std::cout << "Test change_a_to_b<std::string>: ";
  iter(generic, 3, change_a_to_b);
  iter(generic, 3, print<std::string>);
  std::cout << '\n';

  return 0;
}
