/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:06:51 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/04 15:11:17 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cctype>
#include <cstdlib>
#include <iostream>

static std::string formatString(std::string str) {
  if (str.length() <= 10)
    return str;
  str.resize(10);
  str[9] = '.';
  return str;
}

static void printWithPadding(std::string str) {
  std::cout.width(10);
  std::cout << std::right << str << '|';
}

static void printWithPadding(unsigned int index) {
  std::cout.width(10);
  std::cout << std::right << index << '|';
}

static void printFormatedString(Contact const *currentContact,
                                unsigned int index) {
  std::string formatedName, formatedLastName, formatedNickName;

  formatedName = formatString(currentContact->getFirstName());
  formatedLastName = formatString(currentContact->getLastName());
  formatedNickName = formatString(currentContact->getNickName());

  printWithPadding(index);
  printWithPadding(formatedName);
  printWithPadding(formatedLastName);
  printWithPadding(formatedNickName);
  std::cout << std::endl;
}

void printListContacts(PhoneBook const &book) {
  unsigned int bookSize = book.getBookSize();
  std::string valueToPrint;
  Contact currentContact;

  bookSize = bookSize < 8 ? bookSize : 8;
  for (unsigned int i = 0; i < bookSize; i++) {
    currentContact = book.getContact(i);
    printFormatedString(&currentContact, i);
  }
}

void printHeader(void) {
  printWithPadding("Index");
  printWithPadding("Name");
  printWithPadding("LastName");
  printWithPadding("NickName");
  std::cout << std::endl;
}

void printContactInformation(Contact const &toPrint) {
  std::cout << std::endl;
  std::cout << "FirstName: " << toPrint.getFirstName() << std::endl;
  std::cout << "LastName: " << toPrint.getLastName() << std::endl;
  std::cout << "NickName: " << toPrint.getNickName() << std::endl;
  std::cout << "PhoneNumber: " << toPrint.getPhoneNumber() << std::endl;
  std::cout << "DarkestSecret: " << toPrint.getDarkestSecret() << std::endl;
}

bool validateNames(std::string const name) {
  for (unsigned int i = 0; i < name.length(); i++) {
    if (!std::isalpha(name[i])) {
      return false;
    }
  }
  return true;
}

bool validateNumber(std::string const number) {
  for (unsigned int i = 0; i < number.length(); i++) {
    if (!std::isdigit(number[i])) {
      return false;
    }
  }
  return true;
}

std::string getValueFromCIN(void) {
  std::string value;

  std::cin >> value;
  if (std::cin.eof()) {
    std::cout << std::endl;
    exit(1);
  }
  return value;
}

Contact getNewContact(void) {
  std::string firstName;
  std::string lastName;
  std::string nickName;
  std::string phoneNumber;
  std::string darkestSecret;

  std::cout << "FirstName: ";
  firstName = getValueFromCIN();
  std::cout << "LastName: ";
  lastName = getValueFromCIN();
  std::cout << "nickName: ";
  nickName = getValueFromCIN();
  std::cout << "phoneNumber: ";
  phoneNumber = getValueFromCIN();
  std::cout << "darkestSecret: ";
  darkestSecret = getValueFromCIN();

  return Contact(firstName, lastName, nickName, phoneNumber, darkestSecret);
}

bool validateContact(Contact const &newContact) {
  return (validateNames(newContact.getFirstName()) &&
          validateNames(newContact.getLastName()) &&
          validateNumber(newContact.getPhoneNumber()));
}
