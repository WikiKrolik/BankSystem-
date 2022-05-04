#ifndef NEWONE_CLIENT_H
#define NEWONE_CLIENT_H

#include "Account.h"
#include "NormalAccount.h"
#include "SavingsAccount.h"
#include "CreditAccount.h"
#include <string>
#include <vector>
#include <memory>

class Client{
private:
    std::string clientPesel;
    std::string clientName;
    std::string clientSurname;
    std::string clientAddress;
    long int clientPhone;
    std::string clientPassword;


    std::vector<std::shared_ptr<Account>> accounts;
public:

    Client(const std::string &clientPesel, const std::string &clientName, const std::string &clientSurname,
           const std::string &clientAddress, long clientPhone, const std::string &clientPassword);

    void addAccount(std::shared_ptr<Account> account);

    virtual ~Client();

    bool validatePassword(std::string pesel, std::string password);

    unsigned int countAccounts();

    //getters

    const std::string &getClientPesel() const;

    const std::string &getClientName() const;

    const std::string &getClientSurname() const;

    const std::string &getClientAddress() const;

    long getClientPhone() const;
};

#endif