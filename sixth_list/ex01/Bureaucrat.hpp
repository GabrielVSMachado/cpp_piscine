/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:09:02 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/09 14:14:27 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "BureaucracyConstitution.hpp"
#include <exception>
#include <ostream>
#include <string>

class Bureaucrat : public BureaucracyConstitution {
  public:
    Bureaucrat();
    Bureaucrat(Bureaucrat const &);
    Bureaucrat &operator=(Bureaucrat const &);
    virtual ~Bureaucrat();

    unsigned int const &getGrade() const;

    Bureaucrat(std::string const &, unsigned int const &) throw(
        GradeTHExcpt, GradeTLExcpt);

    void incrementGrade(int const &) throw(GradeTHExcpt, GradeTLExcpt);
    void decresceGrade(int const &) throw(GradeTLExcpt, GradeTHExcpt);

  private:
    unsigned int _grade;
};

std::ostream &operator<<(std::ostream &, Bureaucrat const &);
#endif // !Bureaucrat
