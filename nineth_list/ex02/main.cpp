/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 23:40:31 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/29 00:47:18 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <iostream>
#include "MutantStack.hpp"

int main ()
{
  {
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << '\n';
    mstack.pop();

    std::cout << mstack.size() << '\n';

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite)
    {
      std::cout << *it << '\n';
      ++it;
    }

    std::stack<int> s(mstack);
  }
  {
    MutantStack<std::string> strStack;

    strStack.push("Aragorn");
    strStack.push("Gandalf");

    std::cout << strStack.top() << '\n';
    strStack.pop();
    std::cout << strStack.top() << '\n';
    strStack.pop();

    strStack.push("I");
    strStack.push("II");
    strStack.push("III");

    MutantStack<std::string>::iterator it = strStack.begin();
    MutantStack<std::string>::iterator ite = strStack.end();

    while (it != ite) {
      std::cout << *it << ' ';
      ++it;
    }
    std::cout << '\n';
  }
  return 0;
}
