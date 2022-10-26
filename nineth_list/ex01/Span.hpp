/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:40:39 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/25 23:43:18 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <list>

class NoSpanFounded : public std::exception {
  public:
    NoSpanFounded();
    virtual char const* what() const throw();
};

class LimitReached : public std::exception {
  public:
    LimitReached();
    virtual char const* what() const throw();
};

class Span {
  public:
    Span();
    Span(Span const &);
    Span(unsigned int const &);
    Span &operator=(Span const &);
    virtual ~Span();

    void addNumbers(
        std::list<int>::iterator const& begin,
        std::list<int>::iterator const& end
        ) throw(LimitReached);
    void addNumber(int const &) throw(LimitReached);
    int shortestSpan() throw(NoSpanFounded);
    int longestSpan() throw(NoSpanFounded);

  private:
    std::list<int> _list;
    unsigned int _limit;
};

#endif // !SPAN_HPP
