/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 13:18:05 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/09 15:33:33 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "BureaucracyConstitution.hpp"
#include "Bureaucrat.hpp"
#include <exception>
#include <ostream>
#include <string>

class Form : public BureaucracyConstitution {
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

    void beSigned(Bureaucrat const &) throw(GradeTHExcpt, GradeTLExcpt);

  private:
    bool _isSigned;
    unsigned int const _requiredSign;
    unsigned int const _requiredExecute;
};

std::ostream& operator<<(std::ostream&, Form const &);
#endif // !FORM_HPP
