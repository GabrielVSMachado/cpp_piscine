/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 11:43:19 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/11/02 22:11:45 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <vector>
#include "NotFoundException.hpp"

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
