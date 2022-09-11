/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 23:54:40 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/11 11:46:33 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) { return; }
Weapon::~Weapon(void) { return; }

Weapon::Weapon(std::string type) : _type(type) { return; }

std::string const &Weapon::getType(void) const { return this->_type; }

void Weapon::setType(std::string newType) { this->_type = newType; }
