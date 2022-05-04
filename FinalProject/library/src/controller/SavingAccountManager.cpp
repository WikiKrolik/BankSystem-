//
// Created by student on 1/21/22.
//
#include <iostream>
#include "controller/SavingAccountManager.h"

void SavingAccountManager::deposit(double amount,std::shared_ptr<Account> account) {
    account->checkPin();
    double x = account->getBalance();
    x = x + amount;
    account->setBalance(x);

}

double SavingAccountManager::checkBalance(std::shared_ptr<Account> account) {
//    std::cout<<"Interest Rate: "<<account->getInterestRate()<<std::endl;
//    std::cout<<"Balance: ";
    return  account->getBalance();
}

void SavingAccountManager::addSavings(float interest, std::shared_ptr<Account> account) {
    double x = account->getBalance();
    x = x * interest;
    account->setBalance(x);
}

void SavingAccountManager::withdraw(double amount, std::shared_ptr<Account> account) {
    std::cout<<"You cannot withdraw money from this account."<<std::endl;
}
