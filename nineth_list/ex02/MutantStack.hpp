/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 23:20:36 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/27 23:47:08 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iterator>

template<typename T>
class MutantStack : public std::stack<T> {
public:
  MutantStack();
  MutantStack(MutantStack const &);
  MutantStack &operator=(MutantStack const &);
  virtual ~MutantStack();

  std::iterator<std::random_access_iterator_tag, std::stack<T>>
    begin();

  std::iterator<std::random_access_iterator_tag, std::stack<T>>
    end();
};

#endif // !MUTANTSTACK_HPP
