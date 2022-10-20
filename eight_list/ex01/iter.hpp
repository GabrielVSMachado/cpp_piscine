/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:53:43 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/20 17:54:20 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template<typename T, typename U>
void iter(T * const array, size_t const &length, U fn) {
  for (size_t i = 0; i < length; i++) {
    fn(array[i]);
  }
}

#endif
