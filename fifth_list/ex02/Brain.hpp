/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:44:48 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/27 19:20:23 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
public:
  Brain(void);
  Brain(Brain const &);
  Brain &operator=(Brain const &);
  virtual ~Brain(void);

  void setNewIdea(int, std::string const &);
  std::string getIdea(int) const;

private:
  std::string _ideas[100];
};

#endif // !BRAIN_HPP
