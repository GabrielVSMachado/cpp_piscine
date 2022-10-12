/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 01:47:53 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/04 01:48:11 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "utils.hpp"
#include <iostream>

int main(void) {
  PhoneBook book;
  std::string inputCommand;

  std::cout << std::endl;
  std::cout << "You can enter one of the three commands: ADD, SEARCH and EXIT"
            << std::endl;
  std::cout << "ADD: add a new contact into phone book." << std::endl;
  std::cout << "SEARCH: search information from contacts in the phone book."
            << std::endl;
  std::cout << "EXIT: exit the program." << std::endl;

  do {
    std::cout << "\nEnter the wanted command: ";
    inputCommand = getValueFromCIN();

    if (inputCommand == "ADD") {

      if (!book.add()) {
        std::cerr << std::endl;
        std::cerr << "FirstName and LastName must be only letters. "
          << "PhoneNumber must be only numbers." << std::endl;
        continue;
      }
      std::cout << "User added with success" << std::endl;

    }
    else if (inputCommand == "SEARCH") {
      PhoneBook::search(book);
    }
    else if (inputCommand != "EXIT") {
      std::cout << "Invalid Command !!!" << std::endl;
      continue;
    }

  } while (inputCommand != "EXIT");
  return 0;
}
