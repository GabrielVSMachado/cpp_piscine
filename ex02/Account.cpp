/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 23:49:28 by gvitor-s          #+#    #+#             */
/*   Updated: 2022/09/05 23:49:35 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <cerrno>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <system_error>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(void)
    : _amount(0), _accountIndex(Account::_nbAccounts), _nbDeposits(0),
      _nbWithdrawals(0) {
  Account::_displayTimestamp();
  std::cout << "index:" << Account::_nbAccounts << ';';
  std::cout << "amount:" << 0 << ';';
  std::cout << "created" << std::endl;
  ++Account::_nbAccounts;
  return;
}

Account::~Account(void) {
  std::cout << "index:" << this->_accountIndex << ';';
  std::cout << "amount:" << this->_amount << ';';
  std::cout << "closed" << std::endl;
  Account::_totalAmount -= this->_amount;
  ++Account::_totalNbWithdrawals;
  --Account::_nbAccounts;
  return;
}

Account::Account(int initial_deposit)
    : _amount(initial_deposit), _accountIndex(Account::_nbAccounts),
      _nbDeposits(1), _nbWithdrawals(0) {
  Account::_displayTimestamp();
  std::cout << "index:" << Account::_nbAccounts << ';';
  std::cout << "amount:" << initial_deposit << ';';
  std::cout << "created" << std::endl;
  ++Account::_nbAccounts;
  Account::_totalAmount += initial_deposit;
  ++Account::_totalNbDeposits;
  return;
}

void Account::makeDeposit(int deposit) {
  if (deposit < 0) {
    return;
  }
  this->_amount += deposit;
  Account::_totalAmount += deposit;
  ++this->_nbDeposits;
  ++Account::_totalNbDeposits;
}

bool Account::makeWithdrawal(int withdrawal) {
  if (withdrawal < 0 || withdrawal > this->_amount) {
    std::cout << "index:" << this->_accountIndex << ';';
    std::cout << "p_amount:" << this->_amount << ';';
    std::cout << "withdrawal:refused" << std::endl;
    return false;
  }
  std::cout << "index:" << this->_accountIndex << ';';
  std::cout << "p_amount:" << this->_amount << ';';
  std::cout << "withdrawal:" << withdrawal << ';';
  this->_amount -= withdrawal;
  Account::_totalAmount -= withdrawal;
  ++this->_nbWithdrawals;
  ++Account::_totalNbWithdrawals;
  std::cout << "amount:" << this->_amount << ';';
  std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
  return true;
}

void Account::displayStatus(void) const {
  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ';';
  std::cout << "amount:" << this->_amount << ';';
  std::cout << "deposits:" << this->_nbDeposits << ';';
  std::cout << "withdrawals:" << this->_nbWithdrawals << ';';
}

void Account::displayAccountsInfos(void) {
  Account::_displayTimestamp();
  std::cout << "accounts:" << Account::_nbAccounts << ';';
  std::cout << "total:" << Account::_totalAmount << ';';
  std::cout << "deposits:" << Account::_totalNbDeposits << ';';
  std::cout << "withdrawals:" << Account::_totalNbWithdrawals << ';';
}

void Account::_displayTimestamp(void) {
  time_t timer = {0};
  struct tm *ltime = NULL;
  std::string month;
  std::string day;
  std::string hour;
  std::string minutes;
  std::string seconds;

  timer = time(0);
  if (timer < 0) {
    exit(errno);
  }

  ltime = localtime(&timer);
  std::cout << '[' << ltime->tm_year + 1900;
  month = ltime->tm_mon < 10 ? '0' + ltime->tm_mon : ltime->tm_mon;
  day = ltime->tm_mday < 10 ? '0' + ltime->tm_mday : ltime->tm_mday;
  hour = ltime->tm_hour < 10 ? '0' + ltime->tm_hour : ltime->tm_hour;
  minutes = ltime->tm_min < 10 ? '0' + ltime->tm_min : ltime->tm_min;
  seconds = ltime->tm_sec < 10 ? '0' + ltime->tm_sec : ltime->tm_sec;
  std::cout << month << day << '_' << hour << minutes << seconds << "] ";
}

int Account::getNbAccounts(void) { return Account::_nbAccounts; }

int Account::getTotalAmount(void) { return Account::_totalAmount; }

int Account::getNbDeposits(void) { return Account::_totalNbDeposits; }

int Account::getNbWithdrawals(void) { return Account::_totalNbWithdrawals; }
