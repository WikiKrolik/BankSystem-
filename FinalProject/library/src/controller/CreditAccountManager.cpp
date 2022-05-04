//
// Created by student on 1/21/22.
//

#include "controller/CreditAccountManager.h"




void CreditAccountManager::withdraw(double amount,std::shared_ptr<Account> account) {
    account->checkPin();
    double x= account->getBalance();
    x= x-amount;
    account->setBalance(x);
}

void CreditAccountManager::deposit(double amount,std::shared_ptr<Account> account) {
    account->checkPin();
    double x = account->getBalance();
    x = x + amount;
    account->setBalance(x);
}

double CreditAccountManager::checkBalance(std::shared_ptr<Account> account) {
    return  account->getBalance();
}

CreditAccountManager::CreditAccountManager() {

}

