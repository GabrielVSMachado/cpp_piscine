/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 09:52:41 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/01 01:35:46 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "Ice.hpp"
#include "DropedItens.hpp"

int main (void)
{
  DropedItens test;
  DropedItens test2;
  test.add(new Ice());
  test.add(new Cure());
  test2.add(new Ice());
  test2 = test;
  return 0;
}
