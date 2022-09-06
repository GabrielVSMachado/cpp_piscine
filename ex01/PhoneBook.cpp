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

bool PhoneBook::validateContact(Contact const &newContact) const {
  return (validateNames(newContact.firstName) &&
          validateNames(newContact.lastName) &&
          validateNames(newContact.getNickName()) &&
          validateNumber(newContact.getPhoneNumber()));
}

Contact PhoneBook::getNewContact(void) {
  std::string firstName;
  std::string lastName;
  std::string nickName;
  std::string phoneNumber;
  std::string darkestSecret;

  std::cout << "FirstName: ";
  std::cin >> firstName;
  std::cout << "LastName: ";
  std::cin >> lastName;
  std::cout << "nickName: ";
  std::cin >> nickName;
  std::cout << "phoneNumber: ";
  std::cin >> phoneNumber;
  std::cout << "darkestSecret: ";
  std::cin >> darkestSecret;

  Contact newContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
  return newContact;
}

bool PhoneBook::add(void) {
  Contact newContact = PhoneBook::getNewContact();

  if (this->validateContact(newContact)) {
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

  while (true) {
    std::cout << "Input contact's index wanted: ";
    std::cin >> inputIndex;
    if (validateNumber(inputIndex)) {
      break;
    }
    std::cout << "Index must a positive number: " << std::endl;
  }

  index = std::atoi(inputIndex.c_str());

  if (index > book.getBookSize()) {
    std::cout << "Index out of range" << std::endl;
    return;
  }
  printContactInformation(book.getContact(index));
}
