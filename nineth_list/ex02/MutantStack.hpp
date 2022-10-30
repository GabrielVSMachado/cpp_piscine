/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 23:20:36 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/29 00:45:49 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T> {
  public:
    MutantStack() {}
    MutantStack(MutantStack const &other) { *this = other; }
    MutantStack &operator=(MutantStack const &other) { this->c = other.c; }
    virtual ~MutantStack() {}

    typedef typename std::deque<T>::iterator iterator;

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
};

#endif // !MUTANTSTACK_HPP
