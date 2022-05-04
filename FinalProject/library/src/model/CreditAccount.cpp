//
// Created by student on 1/19/22.
//

#include <sstream>
#include "model/CreditAccount.h"




CreditAccount::CreditAccount(double balance, const std::string &peselNumber, long long int accountNumber, double limit,
                             float creditCost) : Account(balance, peselNumber, accountNumber), Limit(limit),
                                                 CreditCost(creditCost) {}

double CreditAccount::getLimit() const {
    return Limit;
}

float CreditAccount::getCreditCost() const {
    return CreditCost;
}

std::string CreditAccount::toString() {
    std::stringstream ss;
    ss << "Credit Account: " << AccountNumber << ", balance- " << getBalance() <<", Pesel- " << getPeselNumber() << " , Limit- " << getLimit();

    return ss.str();
}

