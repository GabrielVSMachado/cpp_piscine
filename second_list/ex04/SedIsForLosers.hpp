/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedIsForLosers.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 12:38:27 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/11 16:18:26 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEDISFORLOSERS_HPP
#define SEDISFORLOSERS_HPP

#include <fstream>
#include <iostream>

class SedIsForLosers {
public:
  SedIsForLosers(void);
  ~SedIsForLosers(void);

  void changeWordsAndWriteInOffFile(std::string s1, std::string s2);
  void setFileToRead(std::ifstream& fileReadName);
  bool createOffStream(std::string fileName);

private:
  std::ifstream* _fileToRead;
  std::ofstream _fileToWrite;
};

#endif // !SEDISFORLOSERS_HPP
