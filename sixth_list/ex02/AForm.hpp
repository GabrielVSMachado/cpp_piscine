/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 13:18:05 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/29 14:27:50 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AFORM_HPP
#define AFORM_HPP

#include "Exceptions.hpp"
#include <ostream>
#include <string>

class Bureaucrat;

class AForm {
  public:
    AForm();
    AForm(AForm const &);
    AForm(
        std::string const &,
        bool const &,
        unsigned int const &,
        unsigned int const &
    ) throw(GradeTLExcpt, GradeTHExcpt);
    AForm& operator=(AForm const &);
    virtual ~AForm();

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

std::ostream& operator<<(std::ostream&, AForm const &);
#endif // !FORM_HPP
