//
// Created by student on 1/16/22.
//

#ifndef FINALPROJECT_CLIENT_H
#define FINALPROJECT_CLIENT_H

#include <string>
#include <vector>
#include<memory>

#include "Address.h"
#include "Account.h"
#include "SavingAccount.h"
#include "NormalAccount.h"
#include "CreditAccount.h"

class Client {
private:

    std::string Password{""};
    int ClientID;
    std::string Name{""};
    std::string Surname{""};
    std::string Phone{""};

    std::shared_ptr<Address> C_address = nullptr;


public:
    std::vector<std::shared_ptr<Account>> accounts;

    void addAccount(std::shared_ptr<Account> account);

    void removeAccount(std::shared_ptr<Account> account);

    std::shared_ptr<Address> getAddress() const;

    void setAddress(const std::shared_ptr<Address>& address);

    int setPassword(std::string password);

    int getID();

    std::string setName(std::string fname);

    std::string setSurname(std::string sn);

    std::string setAddress(std::string a);

    std::string setPhone(std::string p);

    const std::string &getName();

    const std::string &getSurname();

    const std::string &getPhone();

    const std::string &getPassword() const;

    Client(int clientId, const std::string &name, const std::string &surname, const std::string &phone);

};


#endif //FINALPROJECT_CLIENT_H
