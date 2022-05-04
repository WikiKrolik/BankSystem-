//
// Created by student on 1/21/22.
//

#ifndef FINALPROJECT_NORMALACCOUNTMANAGER_H
#define FINALPROJECT_NORMALACCOUNTMANAGER_H

#include <memory>
#include "AccountManager.h"
#include "model/Account.h"

class NormalAccountManager: public AccountManager {
public:

    double checkBalance(std::shared_ptr<Account> account) override;

    void withdraw(double amount,std::shared_ptr<Account> account) override;

    void deposit(double amount,std::shared_ptr<Account> account) override;
};


#endif //FINALPROJECT_NORMALACCOUNTMANAGER_H
