//
// Created by student on 1/19/22.
//

#include <sstream>
#include "model/NormalAccount.h"

NormalAccount::NormalAccount(double balance, const std::string &peselNumber, long long int accountNumber) : Account(
        balance, peselNumber, accountNumber) {}

std::string NormalAccount::toString() {
        std::stringstream ss;
    ss << "Normal Account: " << AccountNumber << ", balance- " << getBalance() <<", Pesel- " << getPeselNumber();

    return ss.str();
}
