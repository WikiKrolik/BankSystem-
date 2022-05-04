//
// Created by student on 1/17/22.
//
#include <iostream>
#include <sstream>
#include <algorithm>
#include <model/Bank.h>
#include <controller/SavingAccountManager.h>
#include <controller/CreditAccountManager.h>
//#include <ncurses.h>
#include "model/Client.h"
#include "controller/AccountManager.h"
#include "controller/NormalAccountManager.h"

using namespace std;
NormalAccountManager normal_man;
SavingAccountManager saving_man;
CreditAccountManager credit_man;

int main() {
    Bank mBank(1,10000);
    auto client1 = make_shared<Client>(1, "Anna", "Nowak", "444333222");
    mBank.addClient(client1);
    auto account1 = make_shared<NormalAccount>(222.0, "0120999", 339999111100003333);
    client1->addAccount(account1);
//  cout << account1->toString() << endl;
//  cout << man.checkBalance(account1)  << endl;
    account1->setPin(2137);
//  man.deposit(100, account1);
//  cout << account1->getBalance() << endl;
   saving_man.withdraw(220, account1);


    return 0;



}

