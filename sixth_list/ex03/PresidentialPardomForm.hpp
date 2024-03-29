/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardomForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:13:29 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/29 15:07:48 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDOMFORM_HPP
#define PRESIDENTIALPARDOMFORM_HPP

#include "Form.hpp"
#include <string>

class PresidentialPardomForm : virtual public Form {
  public:
    PresidentialPardomForm();
    PresidentialPardomForm(std::string const &);
    PresidentialPardomForm(PresidentialPardomForm const &);
    virtual ~PresidentialPardomForm();

    virtual void doTheExecution() const;
};

#endif // !PresidentialPardomForm_hpp
