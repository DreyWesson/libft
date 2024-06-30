/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduwoledare <oduwoledare@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 10:18:28 by oduwoledare       #+#    #+#             */
/*   Updated: 2023/10/29 20:25:22 by oduwoledare      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int    Account::_nbAccounts = 0;
int    Account::_totalAmount = 0;
int    Account::_totalNbDeposits = 0;
int    Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    this->_accountIndex = this->getNbAccounts();
    this->_amount = initial_deposit;
    Account::_totalAmount += initial_deposit;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:"
              << this->checkAmount() << ";created" << std::endl;
    Account::_nbAccounts++;
}

Account::~Account() {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:"
              << this->checkAmount() << ";closed" << std::endl;
    Account::_nbAccounts--;
}

int Account::getNbAccounts(void) {
    return (Account::_nbAccounts);
}

int Account::getTotalAmount(void) {
    return (Account::_totalAmount);
}

int Account::getNbDeposits(void) {
    return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(void) {
    return (Account::_totalNbWithdrawals);
}

int Account::checkAmount(void) const {
    return (this->_amount);
}

void Account::_displayTimestamp(void) {
    time_t t = time(NULL);

    tm *local_time = localtime(&t);
    std::cout << "[" << local_time->tm_year + 1900;
    std::cout << std::setw(2) << std::setfill('0') << local_time->tm_mon;
    std::cout << std::setw(2) << std::setfill('0') << local_time->tm_mday;
    std::cout << "_" << std::setw(2) << std::setfill('0') << local_time->tm_hour;
    std::cout << std::setw(2) << std::setfill('0') << local_time->tm_min;
    std::cout << std::setw(2) << std::setfill('0') << local_time->tm_sec << "] ";
}

void Account::displayAccountsInfos(void) {
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts() << ";total:"
              << Account::getTotalAmount() << ";deposits:" << Account::getNbDeposits()
              << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void Account::displayStatus(void) const {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:"
              << this->checkAmount() << ";deposits:" << this->_nbDeposits
              << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
    this->_nbDeposits++;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount
              << ";deposit:" << deposit << ";amount:" << this->_amount + deposit
              << ";nb_deposits:" << this->_nbDeposits << std::endl;
    this->_amount += deposit;
    Account::_totalNbDeposits++;
    Account::_totalAmount += deposit;
}

bool Account::makeWithdrawal(int withdrawal) {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:"
              << this->_amount << ";withdrawal:";
    if (withdrawal > this->checkAmount()) {
        std::cout << "refused" << std::endl;
        return (false);
    }
    this->_nbWithdrawals++;
    Account::_totalNbWithdrawals++;
    std::cout << withdrawal << ";amount:" << this->checkAmount() - withdrawal
              << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    this->_amount -= withdrawal;
    Account::_totalAmount -= withdrawal;
    return (true);
}
