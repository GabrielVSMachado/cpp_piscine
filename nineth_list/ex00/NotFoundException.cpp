/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NotFoundException.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 22:10:12 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/11/02 22:11:26 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NotFoundException.hpp"

NotFoundException::NotFoundException() {}

char const* NotFoundException::what() const throw() {
  return "Not found value in container passed";
}
