//
// Created by student on 1/16/22.
//

#ifndef FINALPROJECT_ACCOUNT_H
#define FINALPROJECT_ACCOUNT_H
#include <string>


class Account {
private:

    double balance;
    int Pin;
    std::string PeselNumber{""};

public:

    long long int AccountNumber;

    Account(double balance, const std::string &peselNumber, long long int accountNumber);

    double getBalance() const;

    int getPin() const;

    const std::string &getPeselNumber() const;

    void setBalance(double balance);

    void setPin(int pin);

    virtual std::string toString();

    void checkPin();
};


#endif //FINALPROJECT_ACCOUNT_H
