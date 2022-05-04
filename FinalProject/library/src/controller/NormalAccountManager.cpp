//
// Created by student on 1/21/22.
//

#include <stdexcept>
#include "controller/NormalAccountManager.h"
#include "model/NormalAccount.h"
#include "model/Account.h"
#include "model/Client.h"


double NormalAccountManager::checkBalance(std::shared_ptr<Account> account) {
    return  account->getBalance();
}

void NormalAccountManager::withdraw(double amount,std::shared_ptr<Account> account) {
account->checkPin();

double x= account->getBalance();
    if(amount > x){
        throw std::invalid_argument( "Balance is too low. Choose smaller amount" );
    }
x= x-amount;
account->setBalance(x);
}

 void NormalAccountManager::deposit(double amount, std::shared_ptr<Account> account) {
    account->checkPin();
double x = account->getBalance();
x = x + amount;
account->setBalance(x);
}

