#ifndef NEWONE_ACCOUNT_H
#define NEWONE_ACCOUNT_H

#include "Loan.h"
#include <string>

class Account {
protected:
    int pin;
    double balance;
    std::string clientPesel;
public:

    bool haveloan = false;

    std::string accountNumber;

    Account(int pin, double balance, const std::string &clientPesel, const std::string &accountNumber);

    virtual ~Account() = default;

    virtual bool canWithdraw(double amount) const = 0;

    int getPin() const;

    double getBalance() const;

    void setBalance(double balance);

    const std::string &getClientPesel() const;

    const std::string &getAccountNumber() const;

    virtual void withdraw(double amount) = 0;

    void deposit(double amount);

    bool haveLoan() const;
};

#endif //NEWONE_ACCOUNT_H
