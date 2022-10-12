/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 13:18:05 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/10 22:22:37 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BureaucracyConstitution.hpp"
#include <exception>
#include <ostream>
#include <string>


#ifndef AFORM_HPP
#define AFORM_HPP

class Bureaucrat;

class AForm : virtual public BureaucracyConstitution {
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
    unsigned int const _requiredSign;
    unsigned int const _requiredExecute;
};

std::ostream& operator<<(std::ostream&, AForm const &);
#endif // !FORM_HPP
