/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 12:50:11 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/04 15:23:58 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "utils.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include <sys/types.h>

PhoneBook::PhoneBook(void) : bookSize(0) { return; }
PhoneBook::~PhoneBook(void) { return; }

Contact PhoneBook::getContact(unsigned int index) const {
  return this->book[index];
}

unsigned int PhoneBook::getBookSize(void) const { return this->bookSize; }

bool PhoneBook::add(void) {
  Contact newContact = getNewContact();

  if (validateContact(newContact)) {
    this->book[this->bookSize % 8] = newContact;
    this->bookSize += 1;
    return true;
  }
  return false;
}

void PhoneBook::search(PhoneBook const &book) {
  std::string inputIndex;
  unsigned int index;

  printHeader();
  printListContacts(book);

  if (!book.bookSize) {
    return;
  }

  while (true) {
    std::cout << "Input contact's index wanted: ";
    inputIndex = getValueFromCIN();

    if (validateNumber(inputIndex)) {
      break;
    }

    std::cerr << std::endl;
    std::cerr << "Index must a positive number !!!" << std::endl;
    std::cerr << std::endl;
  }

  index = std::atoi(inputIndex.c_str());

  if (index > 7 || index >= book.getBookSize()) {
    std::cerr << std::endl;
    std::cerr << "Index out of range !!!" << std::endl;
    return;
  }
  printContactInformation(book.getContact(index));
}
