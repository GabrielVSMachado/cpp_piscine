/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:08:11 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/20 19:15:07 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <stdexcept>

template<typename T>
class Array {
  public:
    Array() : _array(), _size(0) {}

    Array(Array const &other) {
      this->_array = new T[other._size];
      this->_size = other._size;
      *this = other;
    }

    Array(unsigned int n) : _array(new T[n]), _size(n) {}

    Array &operator=(Array const &other) {
      if (this == &other) {
        return *this;
      }
      else if (!other._size && this->_size) {
        delete [] this->_array;
        this->_size = 0;
        this->_array = NULL;
        return *this;
      } else if (other._size != this->_size) {
        delete [] this->_array;
        this->_array = new T[other._size];
        this->_size = other._size;
      }

      for (unsigned int i = 0; i < other._size; ++i) {
        this->_array[i] = other._array[i];
      }
      return *this;
    }

    T &operator[](unsigned int const& index) throw(std::out_of_range) {
      if (index < 0 || index > this->_size - 1) {
        throw std::exception();
      }
      return this->_array[index];
    }

    virtual ~Array() { delete [] this->_array; }

    unsigned int const &size() const { return this->_size; }

  private:
    T *_array;
    unsigned int _size;
};

#endif // !ARRAY_HPP
