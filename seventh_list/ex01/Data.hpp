/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:09:25 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/17 20:29:36 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

typedef unsigned long uintptr_t;

class Data {
public:
  Data();
  Data(int const &);
  Data(Data const &);
  Data &operator=(Data const &);
  virtual ~Data();

  int const &getStupidInt() const;
  static uintptr_t serialize(Data* ptr);
  static Data* deserialize(uintptr_t raw);

private:
  int _stupid;
};

#endif // !DATA_HPP
