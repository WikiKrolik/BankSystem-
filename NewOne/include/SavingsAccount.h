//
// Created by student on 2/3/22.
//

#ifndef NEWONE_SAVINGSACCOUNT_H
#define NEWONE_SAVINGSACCOUNT_H
#include <Account.h>

class SavingsAccount : public Account{
private:
    float interestRate;
public:
    SavingsAccount(int pin, double balance, const std::string &clientPesel, const std::string &accountNumber,
                   float interestRate);

    bool canWithdraw(double amount) const override;

    void withdraw(double amount) override;

    float getInterestRate();
};


#endif //NEWONE_SAVINGSACCOUNT_H
