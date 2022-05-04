#ifndef NEWONE_BANK_H
#define NEWONE_BANK_H

#include <string>
#include <vector>
#include <memory>
#include "Client.h"
#include "Loan.h"
#include "Account.h"

class Bank{
private:

    unsigned int bankID;
    std::string bankName;
    double bankFunds;
    std::vector<std::shared_ptr<Client>> clients;
    std::vector<std::shared_ptr<Account>> accounts;
    std::vector<std::shared_ptr<Loan>> loans;
public:

    const std::vector<std::shared_ptr<Client>> &getClients() const;

    const std::vector<std::shared_ptr<Account>> &getAccounts() const;

    const std::vector<std::shared_ptr<Loan>> &getLoans() const;

    std::string bankLocation;

    Bank(unsigned int bankId, std::string bankName, double bankFunds, std::string bankLocation);

    virtual ~Bank();

    std::shared_ptr<Client> createClient(const std::string pesel, const std::string name, const std::string surname, const std::string address, long int phone, const std::string password);

    bool peselInUse(std::string pesel);

    bool checkPIN(std::string pesel, int PIN);

    std::string generateAccountNumber();

    std::shared_ptr<Loan> createLoan(const std::string clientPesel, double amount);

    std::shared_ptr<NormalAccount> createNormalAccount(int pin, double balance, std::string pesel, std::string accountNumber);

    std::shared_ptr<CreditAccount> createCreditAccount(int pin, double balance, std::string pesel, std::string accountNumber,double limit, float creditCost);

    std::shared_ptr<SavingsAccount> createSavingsAccount(int pin, double balance, std::string pesel, std::string accountNumber, float interestRate);

    void addClient(std::shared_ptr<Client> client);

    void addAccount(std::shared_ptr<Account> account);

    template<typename T>
    void removeClient(T predicate){
        for(auto it = clients.begin(); it != clients.end(); ++it){
            if(predicate(**it)){
                clients.erase(it);
                break;
            }
        }
    }

    unsigned int countClients();

    //getters
    unsigned int getBankId() const;

    const std::string &getBankName() const;

    double getBankFunds() const;

    const std::string &getBankLocation() const;

    //other functions

    void giveLoan(double amount,std::shared_ptr<Loan> l, std::shared_ptr<Account> account, int day, int month, int year,std::string purpose);

    void payOffLoan(double Amount, std::shared_ptr<Loan> l, std::shared_ptr<Account> account);
};

#endif