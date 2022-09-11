/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 13:14:06 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/11 16:21:32 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedIsForLosers.hpp"
#include <ios>
#include <iostream>
#include <fstream>
#include <string>

int main (int argc, char *argv[])
{
  std::ifstream inFile;
  SedIsForLosers handler;

  if (argc != 4) {
    std::cerr << "Only accept three arguments !!!" << std::endl;
    return 1;
  }

  inFile.open(argv[1]);

  // Same as inFile.fail()
  if ((inFile.rdstate() & std::ifstream::failbit) != 0) {
    std::cerr << "Failed to open file passed !!!" << std::endl;
    return 1;
  }

  handler.setFileToRead(inFile);
  if (!handler.createOffStream(argv[1])) {
    std::cerr << "Failed to create ofstreaming !!!" << std::endl;
    return 1;
  }
  handler.changeWordsAndWriteInOffFile(argv[2], argv[3]);
  return 0;
}
