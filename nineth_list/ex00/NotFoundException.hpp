/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NotFoundException.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 22:09:10 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/11/02 22:11:46 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NOTFOUNDEXCEPTION_HPP
#define NOTFOUNDEXCEPTION_HPP

#include <exception>

class NotFoundException : std::exception {
  public:
    NotFoundException();
    virtual char const* what() const throw();
};


#endif // !NotFoundException_hpp
