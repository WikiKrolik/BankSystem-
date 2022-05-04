//
// Created by student on 1/21/22.
//

#ifndef FINALPROJECT_SAVINGACCOUNTMANAGER_H
#define FINALPROJECT_SAVINGACCOUNTMANAGER_H


#include <model/SavingAccount.h>
#include "AccountManager.h"

class SavingAccountManager : public AccountManager {
public:

    double checkBalance(std::shared_ptr<Account> account) override;

    void deposit(double amount,std::shared_ptr<Account> account) override;

    void addSavings(float interest, std::shared_ptr<Account> account);

    void withdraw(double amount, std::shared_ptr<Account> account);
};


#endif //FINALPROJECT_SAVINGACCOUNTMANAGER_H
