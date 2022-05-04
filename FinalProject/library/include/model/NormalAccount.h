//
// Created by student on 1/19/22.
//

#ifndef FINALPROJECT_NORMALACCOUNT_H
#define FINALPROJECT_NORMALACCOUNT_H
#include "Account.h"
#include "model/NormalAccount.h"

class NormalAccount: public Account {
public:

    NormalAccount(double balance, const std::string &peselNumber, long long int accountNumber);

    std::string toString() override;

};


#endif //FINALPROJECT_NORMALACCOUNT_H
