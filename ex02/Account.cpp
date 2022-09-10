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

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(void)
    : _accountIndex(Account::_nbAccounts), _amount(0), _nbDeposits(0),
      _nbWithdrawals(0) {
  Account::_displayTimestamp();
  std::cout << "index:" << Account::_nbAccounts << ';';
  std::cout << "amount:" << 0 << ';';
  std::cout << "created" << std::endl;
  ++Account::_nbAccounts;
  return;
}

Account::~Account(void) {
  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ';';
  std::cout << "amount:" << this->_amount << ';';
  std::cout << "closed" << std::endl;
  Account::_totalAmount -= this->_amount;
  ++Account::_totalNbWithdrawals;
  --Account::_nbAccounts;
  return;
}

Account::Account(int initial_deposit)
    : _accountIndex(Account::_nbAccounts), _amount(initial_deposit),
      _nbDeposits(0), _nbWithdrawals(0) {
  Account::_displayTimestamp();
  std::cout << "index:" << Account::_nbAccounts << ';';
  std::cout << "amount:" << initial_deposit << ';';
  std::cout << "created" << std::endl;
  ++Account::_nbAccounts;
  Account::_totalAmount += initial_deposit;
  return;
}

void Account::makeDeposit(int deposit) {
  Account::_displayTimestamp();
  if (deposit < 0) {
    return;
  }
  std::cout << "index:" << this->_accountIndex << ';';
  std::cout << "p_amount:" << this->_amount << ';';
  std::cout << "deposit:" << deposit << ';';
  this->_amount += deposit;
  Account::_totalAmount += deposit;
  ++this->_nbDeposits;
  ++Account::_totalNbDeposits;
  std::cout << "amount:" << this->_amount << ';';
  std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
  Account::_displayTimestamp();
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
  std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::displayAccountsInfos(void) {
  Account::_displayTimestamp();
  std::cout << "accounts:" << Account::_nbAccounts << ';';
  std::cout << "total:" << Account::_totalAmount << ';';
  std::cout << "deposits:" << Account::_totalNbDeposits << ';';
  std::cout << "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

static void printFormatedNumber(int number) {
  if (number < 10) {
    std::cout << "0";
  }
  std::cout << number;
}

void Account::_displayTimestamp(void) {
  time_t timer = {0};
  struct tm *ltime = NULL;
  std::string month;

  timer = time(0);
  if (timer < 0) {
    exit(errno);
  }

  ltime = localtime(&timer);
  std::cout << '[' << ltime->tm_year + 1900;
  printFormatedNumber(ltime->tm_mon);
  printFormatedNumber(ltime->tm_mday);
  std::cout << "_";
  printFormatedNumber(ltime->tm_hour);
  printFormatedNumber(ltime->tm_min);
  printFormatedNumber(ltime->tm_sec);
  std::cout << "] ";
}

int Account::getNbAccounts(void) { return Account::_nbAccounts; }

int Account::getTotalAmount(void) { return Account::_totalAmount; }

int Account::getNbDeposits(void) { return Account::_totalNbDeposits; }

int Account::getNbWithdrawals(void) { return Account::_totalNbWithdrawals; }
