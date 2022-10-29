/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:11:42 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/29 15:26:36 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"

class Intern {
  public:
    Intern();
    Intern(Intern const &);
    Intern &operator=(Intern const &);
    virtual ~Intern();

    Form* makeForm(std::string const &, std::string const &);

  private:
    static std::string validForms[];
};

#endif // !INTERN_HPP
