/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 13:57:30 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/29 14:20:06 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Exceptions.hpp"

GradeTooHighException::GradeTooHighException() {}

char const *GradeTooHighException::what() const throw() {
  return "BureaucracyConstitution don't allow too high grade.";
}

GradeTooLowException::GradeTooLowException() {}

char const *GradeTooLowException::what() const throw() {
  return "you don't have enough grade to do this job.";
}
