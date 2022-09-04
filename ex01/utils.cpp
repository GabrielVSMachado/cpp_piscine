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

#include "PhoneBook.hpp"
#include "Contact.hpp"
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
  std::cout << std::left << str << '|';
}

static void printWithPadding(unsigned int index) {
  std::cout.width(10);
  std::cout << std::left << index << '|';
}

static void printFormatedString(Contact const *currentContact,
                                unsigned int index) {
  std::string formatedName, formatedLastName, formatedNickName;

  formatedName = formatString(currentContact->firstName);
  formatedLastName = formatString(currentContact->lastName);
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

  bookSize = bookSize < 8 ? bookSize : 7;
  for (unsigned int i = 0; i <= bookSize; i++) {
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
