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
#include <iostream>

int main (void)
{
  Harl harl;

  harl.complain("DEBUG");
  std::cout << std::endl;
  harl.complain("INFO");
  std::cout << std::endl;
  harl.complain("WARNING");
  std::cout << std::endl;
  harl.complain("ERROR");
  std::cout << std::endl;

  return 0;
}
