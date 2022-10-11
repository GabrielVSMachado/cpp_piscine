/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BureaucracyConstitution.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 13:46:27 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/09 14:20:01 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRACYCONSTITUTION_HPP
#define BUREAUCRACYCONSTITUTION_HPP

#include <string>

class BureaucracyConstitution {
  public:
    BureaucracyConstitution();
    BureaucracyConstitution(std::string const &);
    BureaucracyConstitution(BureaucracyConstitution const &);
    BureaucracyConstitution& operator=(BureaucracyConstitution const &);
    virtual ~BureaucracyConstitution();

    class GradeTooHighException : public std::exception {
      public:
        GradeTooHighException();
        virtual char const *what() const throw();
    };

    class GradeTooLowException : public std::exception {
      public:
        GradeTooLowException();
        virtual char const *what() const throw();
    };

    typedef GradeTooHighException GradeTHExcpt;
    typedef GradeTooLowException GradeTLExcpt;

    std::string const &getName() const;

  private:
    std::string const _name;
};

#endif // !ACOMMON_HPP
