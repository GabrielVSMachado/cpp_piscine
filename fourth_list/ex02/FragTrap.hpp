/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 21:13:56 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/23 21:19:57 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
  FragTrap(void);
  FragTrap(FragTrap const &);
  FragTrap(std::string);
  FragTrap &operator=(FragTrap const &);
  ~FragTrap(void);

  void highFivesGuys(void);
  void attack(std::string const &);
};

#endif // !FRAGTRAP_HPP
