/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:18:40 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/29 14:19:07 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <exception>

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

#endif // !ACOMMON_HPP
