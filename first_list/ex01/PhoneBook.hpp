/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 00:03:14 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/04 15:12:59 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
public:
  PhoneBook(void);
  ~PhoneBook(void);

  Contact getContact(unsigned int index) const;
  bool add(void);
  unsigned int getBookSize(void) const;

  static void search(PhoneBook const &book);

private:
  Contact book[8];
  unsigned int bookSize;
};

#endif // !PHONEBOOK_HPP
