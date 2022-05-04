//
// Created by student on 1/17/22.
//

#include <sstream>
#include "model/SavingAccount.h"



SavingAccount::SavingAccount(double balance, const std::string &peselNumber, long long int accountNumber,
                             float interestRate, int duration) : Account(balance, peselNumber, accountNumber),
                                                                 InterestRate(interestRate), Duration(duration) {}

float SavingAccount::getInterestRate() const {
    return InterestRate;
}

int SavingAccount::getDuration() const {
    return Duration;
}

std::string SavingAccount::toString() {
    std::stringstream ss;
    ss << "Saving Account: " << AccountNumber << ", balance- " << getBalance() <<", Pesel- " << getPeselNumber() << " , Duration- " << getDuration();

    return ss.str();
}
