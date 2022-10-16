/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Types.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:31:58 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/15 19:03:59 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Types.hpp"
#include <cctype>
#include <cerrno>
#include <cmath>
#include <cstdlib>

Types::Types() {}

Types::Types(Types const &other)
    : _value_as_char(other._value_as_char), _value_as_int(other._value_as_int),
      _value_as_float(other._value_as_float),
      _value_as_double(other._value_as_double) {}

static bool isNotValidInput(std::string const &word) {
  if (word == "nan" || word == "nanf" || word == "inf" || word == "+inf" ||
      word == "-inf" || word == "inff" || word == "+inff" || word == "-inff") {
    return false;
  }
  for (size_t i = 0; i < word.length(); i++) {
    if (!std::isdigit(word[i]) && word[i] != '.') {
      if (i == word.length() - 1 && word[i] == 'f') {
        return false;
      }
      return true;
    }
  }
  return false;
}

Types::Types(std::string const &original) throw(Overflow, NonValidLiteral) {
  if (original.length() > 1 && isNotValidInput(original)) {
    throw NonValidLiteral();
  } else if (original.length() == 1 && !std::isdigit(original[0])) {
    this->_value_as_char = static_cast<char>(original[0]);
    this->_value_as_double = static_cast<double>(this->_value_as_char);
    this->_value_as_float = static_cast<float>(this->_value_as_char);
    this->_value_as_int = static_cast<int>(this->_value_as_char);
  } else if (original.find('.') == std::string::npos) {
    this->_value_as_int = strtol(original.c_str(), NULL, 10);
    if (errno == ERANGE) {
      throw Overflow();
    }
    this->_value_as_char = static_cast<char>(this->_value_as_int);
    this->_value_as_double = static_cast<double>(this->_value_as_int);
    this->_value_as_float = static_cast<float>(this->_value_as_int);
  } else {
    this->_value_as_double = strtod(original.c_str(), NULL);
    if (errno == ERANGE && (this->_value_as_double == HUGE_VAL ||
                            this->_value_as_double == -HUGE_VAL)) {
      throw Overflow();
    }
    this->_value_as_float = static_cast<float>(this->_value_as_double);
    this->_value_as_char = static_cast<char>(this->_value_as_double);
    this->_value_as_int = static_cast<int>(this->_value_as_double);
  }
}

Types &Types::operator=(Types const &other) {
  this->_value_as_char = other._value_as_char;
  this->_value_as_int = other._value_as_int;
  this->_value_as_float = other._value_as_float;
  this->_value_as_double = other._value_as_double;
  return *this;
}

Types::~Types() {}

char const &Types::getChar() const { return this->_value_as_char; }
int const &Types::getInt() const { return this->_value_as_int; }
float const &Types::getFloat() const { return this->_value_as_float; }
double const &Types::getDouble() const { return this->_value_as_double; }

Types::NonValidLiteral::NonValidLiteral() {}
char const *Types::NonValidLiteral::what() const throw() {
  return "The value passed is not a valid literal.";
}

Types::Overflow::Overflow() {}
char const *Types::Overflow::what() const throw() {
  return "The value Overflow the type capacity";
}
