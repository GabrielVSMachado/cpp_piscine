/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:36:58 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/12 12:21:32 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
  public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string const &);
    RobotomyRequestForm(RobotomyRequestForm const &);
    virtual ~RobotomyRequestForm();

    virtual void doTheExecution() const;
};

#endif // !RobotomyRequestForm_hpp
