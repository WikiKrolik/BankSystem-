//
// Created by student on 1/19/22.
//

#ifndef FINALPROJECT_CREDITACCOUNT_H
#define FINALPROJECT_CREDITACCOUNT_H
#include "Account.h"

class CreditAccount: public Account{
private:

    double Limit;
    float CreditCost;



public:

    CreditAccount(double balance, const std::string &peselNumber, long long int accountNumber, double limit,
                  float creditCost);

    double getLimit() const;

    float getCreditCost() const;

    std::string toString() override;
};


#endif //FINALPROJECT_CREDITACCOUNT_H
