/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 12:34:27 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/04 12:52:44 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) { return; }
Contact::~Contact(void) { return; }

Contact::Contact(std::string firstName, std::string lastName,
                 std::string nickName, std::string phoneNumber,
                 std::string darkestSecret)
    : firstName(firstName), lastName(lastName), nickName(nickName),
      phoneNumber(phoneNumber), darkestSecret(darkestSecret) {
  return;
}

Contact &Contact::operator=(const Contact &newContact) {
  this->darkestSecret = newContact.darkestSecret;
  this->phoneNumber = newContact.phoneNumber;
  this->nickName = newContact.nickName;
  this->lastName = newContact.lastName;
  this->firstName = newContact.firstName;
  return *this;
}

std::string const &Contact::getDarkestSecret(void) const {
  return this->darkestSecret;
}

std::string const &Contact::getNickName(void) const { return this->nickName; }
std::string const &Contact::getPhoneNumber(void) const {
  return this->phoneNumber;
}

std::string const &Contact::getFirstName() const { return this->firstName; }
std::string const &Contact::getLastName() const { return this->lastName; }
