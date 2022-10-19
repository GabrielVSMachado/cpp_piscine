/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 23:21:24 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/18 23:26:24 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template<typename T>
void swap(T &one, T &another) {
  T tmp = one;
  one = another;
  another = tmp;
}

template<typename T>
T const &max(T const &first, T const &second) {
  return first > second ? first : second;
}

template<typename T>
T const &min(T const &first, T const &second) {
  return first < second ? first : second;
}

#endif // !WHATEVER_HPP
