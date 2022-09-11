/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 23:16:49 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/10 23:27:31 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main (void)
{
  std::string str = "HI THIS IS BRAIN";
  std::string* stringPTR = &str;
  std::string& stringREF = str;

  std::cout << "Original address: " << &str << std::endl;
  std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
  std::cout << "Memory address held by stringREF" << &stringREF << std::endl;

  std::cout << "Original value: " << str << std::endl;
  std::cout << "Value in stringPTR: " << *stringPTR << std::endl;
  std::cout << "Value in stringREF: " << stringREF << std::endl;
  return 0;
}
