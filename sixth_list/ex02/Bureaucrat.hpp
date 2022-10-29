/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:09:02 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/29 14:21:14 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "Exceptions.hpp"
#include <ostream>
#include <string>

class AForm;

class Bureaucrat {
  public:
    Bureaucrat();
    Bureaucrat(Bureaucrat const &);
    Bureaucrat &operator=(Bureaucrat const &);
    Bureaucrat(std::string const &, unsigned int const &) throw(
        GradeTHExcpt, GradeTLExcpt);
    virtual ~Bureaucrat();

    unsigned int const &getGrade() const;
    std::string const &getName() const;

    void incrementGrade(int const &) throw(GradeTHExcpt, GradeTLExcpt);
    void decresceGrade(int const &) throw(GradeTLExcpt, GradeTHExcpt);
    void signForm(AForm &) const;
    void executeForm(AForm const &) const;

  private:
    unsigned int _grade;
    std::string const _name;
};

std::ostream &operator<<(std::ostream &, Bureaucrat const &);
#endif // !Bureaucrat
