//
// Created by student on 1/21/22.
//

#ifndef FINALPROJECT_ACCOUNTMANAGER_H
#define FINALPROJECT_ACCOUNTMANAGER_H


#include <string>
#include <memory>
#include <model/Account.h>

class AccountManager {
public:

    virtual double checkBalance(std::shared_ptr<Account> account) = 0;

    virtual void withdraw(double amount,std::shared_ptr<Account> account) = 0;

    virtual void deposit(double amount,std::shared_ptr<Account> account) = 0;

};


#endif //FINALPROJECT_ACCOUNTMANAGER_H
