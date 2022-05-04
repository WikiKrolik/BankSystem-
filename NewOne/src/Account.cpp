#include "Account.h"
#include <iostream>

Account::Account(int pin, double balance, const std::string &clientPesel, const std::string &accountNumber) : pin(pin),
                                                                                                              balance(balance),
                                                                                                              clientPesel(
                                                                                                                      clientPesel),
                                                                                                              accountNumber(
                                                                                                                      accountNumber) {}

int Account::getPin() const {
    return pin;
}

double Account::getBalance() const {
    return balance;
}

void Account::setBalance(double Balance) {
    balance = Balance;
}

const std::string &Account::getClientPesel() const {
    return clientPesel;
}

bool Account::haveLoan() const {
    if (haveloan)
        return true;
    else
        return false;
}

void Account::deposit(double amount) {
    balance+=amount;
}

const std::string &Account::getAccountNumber() const {
    return accountNumber;
}



