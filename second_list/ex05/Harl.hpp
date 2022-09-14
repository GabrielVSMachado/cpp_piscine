/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:55:05 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/13 23:26:28 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl
{
public:
  Harl(void);
  ~Harl(void);

  void complain(std::string level) const;

private:
  void _debug(void) const;
  void _info(void) const;
  void _warning(void) const;
  void _error(void) const;
};

typedef void (Harl::* const HarlMemFn)(void) const;
#endif // !HARL_HPP
