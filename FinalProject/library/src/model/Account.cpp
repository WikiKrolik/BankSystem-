//
// Created by student on 1/16/22.
//

#include <sstream>
#include <iostream>
#include "model/Account.h"




Account::Account(double balance, const std::string &peselNumber, long long int accountNumber) : balance(balance),
                                                                                                PeselNumber(
                                                                                                        peselNumber),
                                                                                                AccountNumber(
                                                                                                        accountNumber) {}

double Account::getBalance() const {
    return balance;
}

int Account::getPin() const {
    return Pin;
}

const std::string &Account::getPeselNumber() const {
    return PeselNumber;
}

void Account::setBalance(double balance) {
    Account::balance = balance;
}

void Account::setPin(int pin) {
    Pin = pin;
}
std::string Account::toString() {
    std::stringstream ss;
    ss << "Account: " << AccountNumber << ", balance- " << getBalance() <<", Pesel- " << getPeselNumber();

    return ss.str();
}

void Account::checkPin() {
    int y;
    y = getPin();
    int x;
     while(x!=y){
        std::cout<<"Enter PIN: " << std::endl;
        std::cin>>x;
        if (x!=y) std::cout<<"Incorrect Pin" << std::endl;

    };

    std::cout<<"Correct Pin" << std::endl;
}
