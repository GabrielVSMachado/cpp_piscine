/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:09:02 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/05 23:16:09 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <ostream>
#include <string>

class Bureaucrat {
public:
  typedef class GradeTooHighException : virtual public std::exception {
  public:
    GradeTooHighException();
    virtual char const *what() const throw();
  } GradeTooHighExpt;

  typedef class GradeTooLowException : public std::exception {
  public:
    GradeTooLowException();
    virtual char const *what() const throw();
  } GradeTooLowExpt;

  Bureaucrat();
  Bureaucrat(Bureaucrat const &);
  Bureaucrat(std::string const &, unsigned int const &) throw(GradeTooHighExpt,
                                                              GradeTooLowExpt);
  Bureaucrat &operator=(Bureaucrat const &);

  virtual ~Bureaucrat();

  std::string const &getName() const;
  unsigned int const &getGrade() const;
  void incrementGrade(int const &) throw(GradeTooHighExpt, GradeTooLowExpt);
  void decresceGrade(int const &) throw(GradeTooLowExpt, GradeTooHighExpt);


private:
  std::string const _name;
  unsigned int _grade;
};

std::ostream &operator<<(std::ostream &, Bureaucrat const &);
#endif // !Bureaucrat
