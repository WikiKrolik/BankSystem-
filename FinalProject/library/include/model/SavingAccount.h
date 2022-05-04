//
// Created by student on 1/17/22.
//

#ifndef FINALPROJECT_SAVINGACCOUNT_H
#define FINALPROJECT_SAVINGACCOUNT_H
#include "Account.h"

class SavingAccount : public Account {
private:

    float InterestRate;
    int Duration;

public:

    SavingAccount(double balance, const std::string &peselNumber, long long int accountNumber, float interestRate,
                  int duration);

    float getInterestRate() const;

    int getDuration() const;

    std::string toString() override;
};


#endif //FINALPROJECT_SAVINGACCOUNT_H
