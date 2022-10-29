/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 23:40:31 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/27 23:43:11 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <iostream>

int main ()
{
  std::stack<int> a;

  try {
    a.push(1);
    a.push(2);
    a.pop();
    a.pop();
    a.pop();
  }
  catch (const std::exception&e) {
    std::cerr << e.what() << '\n';
  }
  return 0;
}
