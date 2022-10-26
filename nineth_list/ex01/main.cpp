/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 22:20:09 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/25 23:43:19 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main ()
{
  {
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "shortestSpan: " << sp.shortestSpan() << '\n';
    std::cout << "longestSpan: " << sp.longestSpan() << '\n';
  }
  {
    Span sp(2);

    try {
      sp.addNumber(1);
      sp.addNumber(2);
      sp.addNumber(3);
    }
    catch (const std::exception&e) {
      std::cerr << e.what() << '\n';
    }
  }
  return 0;
}
