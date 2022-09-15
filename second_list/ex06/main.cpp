/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:16:11 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/14 22:16:15 by gvitor-s         ###   ########.fr       */
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

  if (argc != 2) {
    return 1;
  }

  switch (calcWordHash(argv[1])) {
    case DEBUG:
      std::cout << "[ DEBUG ]" << std::endl;
      harl.complain("DEBUG");
      std::cout << std::endl;
      goto info;
    case INFO:
info:
      std::cout << "[ INFO ]" << std::endl;
      harl.complain("INFO");
      std::cout << std::endl;
      goto warning;
    case WARNING:
warning:
      std::cout << "[ WARNING ]" << std::endl;
      harl.complain("WARNING");
      std::cout << std::endl;
      goto error;
    case ERROR:
error:
      std::cout << "[ ERROR ]" << std::endl;
      harl.complain("ERROR");
      std::cout << std::endl;
      break;
    default:
      std::cout << "[ Probably complaining about insignificant problems ]";
      std::cout << std::endl;
      break;
  }

  return 0;
}
