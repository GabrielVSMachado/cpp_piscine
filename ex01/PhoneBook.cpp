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
#include "utils.hpp"
#include <iostream>
#include <string>

PhoneBook::PhoneBook(void) : bookSize(0) { return; }
PhoneBook::~PhoneBook(void) { return; }

Contact PhoneBook::getContact(unsigned int index) const {
  return this->book[index];
}

unsigned int PhoneBook::getBookSize(void) const { return this->bookSize; }

void PhoneBook::add(Contact const &newContact) {
  this->bookSize += 1;
  this->book[this->bookSize % 8] = newContact;
}

void PhoneBook::search(PhoneBook const &book) {
    std::string inputIndex;

    printHeader();
    printListContacts(book);
    std::cout << "Input contact's index wanted: ";
    std::cin >> inputIndex;
}
