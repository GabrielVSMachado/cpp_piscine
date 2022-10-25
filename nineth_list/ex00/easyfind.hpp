/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 11:43:19 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/23 13:49:10 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <iterator>
#include <vector>

class NotFoundException : std::exception {
  public:
    virtual char const* what() const throw() {
      return "Not found value in container passed";
    }
};

template<typename T>
int& easyfind(T &container, int const &value) throw(NotFoundException) {
  typename T::iterator result;
  if (value == *container.end()) {
    return *container.end();
  }
  result = std::find(container.begin(), container.end(), value);
  if (result != container.end()) {
    return *result;
  }
  throw NotFoundException();
}

#endif // !EASYFIND_HPP
