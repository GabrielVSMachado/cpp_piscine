/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DropedItens.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 00:28:28 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/10/01 23:59:43 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DROPEDITENS_HPP
#define DROPEDITENS_HPP

#include "AMateria.hpp"

class DropedItens {
public:
  DropedItens(void);
  DropedItens(DropedItens const &);
  DropedItens &operator=(DropedItens const &);
  virtual ~DropedItens(void);

  void add(AMateria const *);

private:
  struct Node {
    Node(AMateria const *);
    virtual ~Node(void);
    AMateria const *content;
    Node *next;
    static void clone(Node * &, Node const *);
  };
  Node *_head;
};

#endif // !LINKEDLIST_HPP
