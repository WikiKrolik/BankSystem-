//
// Created by student on 1/21/22.
//

#ifndef FINALPROJECT_CREDITACCOUNTMANAGER_H
#define FINALPROJECT_CREDITACCOUNTMANAGER_H

#include "AccountManager.h"

class CreditAccountManager: public AccountManager {
public:

    CreditAccountManager();

    void withdraw(double amount,std::shared_ptr<Account> account) override;

    void deposit(double amount,std::shared_ptr<Account> account) override;

    double checkBalance(std::shared_ptr<Account> account) override;
};


#endif //FINALPROJECT_CREDITACCOUNTMANAGER_H
