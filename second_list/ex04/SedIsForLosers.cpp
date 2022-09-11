/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedIsForLosers.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 12:55:28 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/11 16:21:29 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedIsForLosers.hpp"
#include <fstream>
#include <ios>
#include <string>

SedIsForLosers::SedIsForLosers(void) { return; };
SedIsForLosers::~SedIsForLosers(void) {
  if (this->_fileToRead->is_open()) {
    this->_fileToWrite.close();
  }
  if (this->_fileToWrite.is_open()) {
    this->_fileToRead->close();
  }
}

void SedIsForLosers::setFileToRead(std::ifstream &fileReadName) {
  this->_fileToRead = &fileReadName;
}

bool SedIsForLosers::createOffStream(std::string fileName) {
  std::string tmp = fileName + ".replace";
  this->_fileToWrite.open(tmp.c_str(), std::fstream::trunc | std::fstream::out);
  return ((this->_fileToWrite.rdstate() & std::ofstream::failbit) == 0);
}

void SedIsForLosers::changeWordsAndWriteInOffFile(std::string s1, std::string s2) {
  std::string line, after, before;
  std::size_t found;

  while (true) {
    std::getline(*this->_fileToRead, line);
    if (this->_fileToRead->eof()) {
      return;
    }

    found = line.find(s1);

    if (found != std::string::npos) {
      before = line.substr(0, found);
      after = line.substr(found + s1.length(),
                          line.length() - (before.length() + s1.length()));
      this->_fileToWrite << before << s2 << after;
    } else {
      this->_fileToWrite << line;
    }

    this->_fileToWrite << std::endl;
  }
}
