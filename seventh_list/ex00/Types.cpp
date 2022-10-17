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
#include <ostream>

Types::Types() {}

Types::Types(Types const &other)
    : _value_as_char(other._value_as_char), _value_as_int(other._value_as_int),
      _value_as_float(other._value_as_float),
      _value_as_double(other._value_as_double) {}

static bool checkMathLimits(std::string const &original) {
  return (original == "nan" || original == "nanf" || original == "inf" ||
          original == "+inf" || original == "-inf" || original == "inff" ||
          original == "+inff" || original == "-inff");
}

static bool isNotValidInput(std::string const &word) {
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

static bool notOverOrUnderFlowInt(std::string const &number) {
  std::string tmp;

  if ((number.length() > 10 && number[0] != '-') ||
      (number.length() > 11 && number[0] == '-')) {
    return true;
  } else if (number.length() < 10) {
    return false;
  }
  tmp = number.substr(0, number.length() - 2);
  if (tmp == "214748364") {
    return number[9] - '0' > 7 ? true : false;
  } else if (tmp == "-214748364") {
    return number[10] - '0' > 8 ? true : false;
  }
  return false;
}

Types::Types(std::string const &original) throw(Overflow, NonValidLiteral)
    : _isMathLimit(checkMathLimits(original)) {
  errno = 0;
  if (original.length() > 1 && !this->_isMathLimit
      && isNotValidInput(original)) {
    throw Types::NonValidLiteral();
  } else if (original.length() == 1 && !std::isdigit(original[0])) {
    this->_value_as_char = static_cast<char>(original[0]);
    this->_value_as_double = static_cast<double>(this->_value_as_char);
    this->_value_as_float = static_cast<float>(this->_value_as_char);
    this->_value_as_int = static_cast<int>(this->_value_as_char);
  } else if (std::isdigit(original[0]) &&
             original.find('.') == std::string::npos) {
    if (notOverOrUnderFlowInt(original)) {
      throw Types::Overflow();
    }
    this->_value_as_int = std::atoi(original.c_str());
    this->_value_as_char = static_cast<char>(this->_value_as_int);
    this->_value_as_double = static_cast<double>(this->_value_as_int);
    this->_value_as_float = static_cast<float>(this->_value_as_int);
  } else {
    this->_value_as_double = strtod(original.c_str(), NULL);
    if (errno == ERANGE && (this->_value_as_double == HUGE_VAL ||
                            this->_value_as_double == -HUGE_VAL)) {
      throw Types::Overflow();
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
bool const &Types::getIsMathLimit() const { return this->_isMathLimit; }

Types::NonValidLiteral::NonValidLiteral() {}
char const *Types::NonValidLiteral::what() const throw() {
  return "The value passed is not a valid literal.";
}

Types::Overflow::Overflow() {}
char const *Types::Overflow::what() const throw() {
  return "The value Overflow the type capacity";
}

std::ostream &operator<<(std::ostream &o, Types const &type) {
  o << "char: ";
  if (std::isprint(type.getChar())) {
    o << type.getChar() << '\n';
  } else if (type.getIsMathLimit()) {
    o << "impossible.\n";
  } else {
    o << "Not displayable.\n";
  }
  o << "int: ";
  if (type.getIsMathLimit()) {
    o << "impossible.\n";
  } else {
    o << type.getInt() << '\n';
  }
  if (!type.getIsMathLimit()
      && ((type.getDouble() * 10 / type.getDouble()) - 100) < 0.00001) {
    o << "float: " << type.getFloat() << ".0f\n";
    o << "double: " << type.getDouble() << ".0";
  } else {
    o << "float: " << type.getFloat() << "f\n";
    o << "double: " << type.getDouble();
  }
  return o;
}
