/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Types.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:46:44 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/15 19:04:00 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_HPP
#define TYPES_HPP

#include <exception>
#include <string>

class Types {
  public:

    class NonValidLiteral : std::exception {
      public:
        NonValidLiteral();
        virtual char const  *what() const throw();
    };

    class Overflow : std::exception {
      public:
        Overflow();
        virtual char const  *what() const throw();
    };

    Types();
    Types(Types const &);
    Types(std::string const &) throw(Overflow, NonValidLiteral);
    Types &operator=(Types const &);
    virtual ~Types();

    char    const &getChar()   const;
    int     const &getInt()    const;
    float   const &getFloat()  const;
    double  const &getDouble() const;

    void display() const;

  private:
    char    _value_as_char;
    int     _value_as_int;
    float   _value_as_float;
    double  _value_as_double;
};

#endif // !Types_hpp
