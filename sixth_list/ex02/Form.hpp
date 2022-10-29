/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:05:08 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/29 15:05:35 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Exceptions.hpp"
#include <ostream>
#include <string>

class Bureaucrat;

class Form {
  public:
    Form();
    Form(Form const &);
    Form(
        std::string const &,
        bool const &,
        unsigned int const &,
        unsigned int const &
    ) throw(GradeTLExcpt, GradeTHExcpt);
    Form& operator=(Form const &);
    virtual ~Form();

    bool const &isSigned() const;
    unsigned int const &getSignGrade() const;
    unsigned int const &getExecuteGrade() const;
    std::string const &getName() const;

    void beSigned(Bureaucrat const &) throw(GradeTLExcpt);

    class NotSignException : public std::exception {
      public:
        NotSignException();
        virtual char const *what() const throw();
    };

    virtual void execute(Bureaucrat const &) const throw(
        NotSignException, GradeTLExcpt);

  protected:
    virtual void doTheExecution() const = 0;

  private:
    bool _isSigned;
    std::string const _name;
    unsigned int const _requiredSign;
    unsigned int const _requiredExecute;
};

std::ostream& operator<<(std::ostream&, Form const &);
#endif // !FORM_HPP
