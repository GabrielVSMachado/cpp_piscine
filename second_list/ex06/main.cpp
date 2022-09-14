/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:03:25 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/14 00:05:11 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <cstring>
#include <iostream>

enum wordHash {
  DEBUG = 359,
  INFO = 300,
  WARNING = 534,
  ERROR = 394
};

static unsigned int calcWordHash(char *word) {
  std::size_t hash = 0;

  for (size_t i = 0; i < std::strlen(word); i++) {
    hash += word[i];
  }
  return hash;
}

int main(int argc, char *argv[]) {

  Harl harl;
  std::size_t value;

  switch (calcWordHash(argv[1])) {
    default:
      break;
  }

  return 0;
}
