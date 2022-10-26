/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:02:47 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/25 23:43:18 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <list>

Span::Span() : _list() {}

Span::Span(Span const &other) { *this = other; }

Span::Span(unsigned int const &n) : _list(), _limit(n) {}

Span& Span::operator=(Span const &other) {
  this->_limit = other._limit;
  this->_list = other._list;
  return *this;
}

Span::~Span() {}

void Span::addNumber(int const &newNum) throw(LimitReached) {
  if (this->_limit == this->_list.size()) {
    throw LimitReached();
  }
  this->_list.push_front(newNum);
}

void Span::addNumbers(
    std::list<int>::iterator const & begin,
    std::list<int>::iterator const & end
    ) throw(LimitReached) {
  for (std::list<int>::iterator tmp = begin; tmp != end; ++tmp) {
    if (this->_list.size() == this->_limit) {
      throw LimitReached();
    }
    this->addNumber(*tmp);
  }
}

static bool compare(int const &first, int const& second) {
  return first < second;
}

int Span::shortestSpan() throw(NoSpanFounded) {
  int result = 0;
  std::list<int>::iterator prev;
  std::list<int>::iterator it;
  std::list<int>::iterator end;

  if (this->_list.size() == 0 || this->_list.size() == 1) {
    throw NoSpanFounded();
  }
  this->_list.sort(compare);
  it = this->_list.begin();
  end = --this->_list.end();
  while (it != end) {
    prev = it++;
    if (!result || std::abs(*it - *prev) < result) {
      result = *it - *prev;
    }
  }
  return result;
}

int Span::longestSpan() throw(NoSpanFounded) {
  if (this->_list.size() == 0 || this->_list.size() == 1) {
    throw NoSpanFounded();
  }
  this->_list.sort(compare);
  return std::abs(*this->_list.rbegin() - *this->_list.begin());
}

NoSpanFounded::NoSpanFounded() {}

char const* NoSpanFounded::what() const throw() {
  return "No Span can be founded !!!";
}

LimitReached::LimitReached() {}

char const* LimitReached::what() const throw() {
  return "The limited was reached.";
}
