#ifndef NEWONE_CREDITACCOUNT_H
#define NEWONE_CREDITACCOUNT_H

#include <Account.h>

class CreditAccount : public Account{
private:
    double limit;

public:
    CreditAccount(int pin, double balance, const std::string &clientPesel, const std::string &accountNumber,
                  double limit, float creditCost);

    bool canWithdraw(double amount) const override;

    void withdraw(double amount) override;

    double getLimit();
};

#endif //NEWONE_CREDITACCOUNT_H
