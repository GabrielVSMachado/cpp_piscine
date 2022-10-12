/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 00:03:01 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/04 15:08:55 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {

public:
  Contact(void);
  ~Contact(void);

  Contact(std::string firstName, std::string lastName, std::string nickName,
          std::string phoneNumber, std::string darkestSecret);

  std::string const &getDarkestSecret() const;
  std::string const &getNickName() const;
  std::string const &getPhoneNumber() const;
  std::string const &getFirstName() const;
  std::string const &getLastName() const;
  Contact &operator=(Contact const &);

private:
  std::string firstName;
  std::string lastName;
  std::string nickName;
  std::string phoneNumber;
  std::string darkestSecret;
};

#endif // !CONTACT_HPP
