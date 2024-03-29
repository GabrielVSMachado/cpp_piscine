/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:10:55 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/04 15:12:54 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP

#include "PhoneBook.hpp"

void printHeader(void);
std::string getValueFromCIN(void);
bool validateNames(std::string const name);
void printListContacts(PhoneBook const &book);
void printContactInformation(Contact const &toPrint);
bool validateNumber(std::string const number);
bool validateContact(Contact const &newContact);
Contact getNewContact(void);
#endif // !UTILS_HPP
