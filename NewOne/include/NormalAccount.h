//
// Created by student on 2/3/22.
//

#ifndef NEWONE_NORMALACCOUNT_H
#define NEWONE_NORMALACCOUNT_H
#include "Account.h"

class NormalAccount : public  Account {
public:
    bool canWithdraw(double amount) const override;

    void withdraw(double amount) override;

    NormalAccount(int pin, double balance, const std::string &clientPesel, const std::string &accountNumber);
};


#endif //NEWONE_NORMALACCOUNT_H
