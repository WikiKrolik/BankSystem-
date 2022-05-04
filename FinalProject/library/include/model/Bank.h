//
// Created by student on 1/16/22.
//

#ifndef FINALPROJECT_BANK_H
#define FINALPROJECT_BANK_H

#include <vector>
#include <memory>
#include <string>
#include "model/Client.h"


class Bank {
private:

    int BankID;
    double Funds;

public:
    std::string Name{""};

    std::string Location{""};

    Bank(int bankId, double funds);

    virtual ~Bank();

    std::vector<std::shared_ptr<Client>> clients;

    bool addClient(std::shared_ptr<Client> client);

    void removeClient(std::shared_ptr<Client> client);

    std::string toString();

    double getFunds() const;

    void LogIn();

};


#endif //FINALPROJECT_BANK_H
