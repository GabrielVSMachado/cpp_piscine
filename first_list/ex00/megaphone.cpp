/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:18:23 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/04 16:18:24 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[]) {
  std::string word;

  if (argc == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return 0;
  }

  for (int i = 1; i < argc; i++) {
    word = argv[i];
    for (size_t j = 0; j < word.length(); j++) {
      std::cout << static_cast<char>(std::toupper(word[j]));
    }
  }
  std::cout << std::endl;
  return 0;
}
