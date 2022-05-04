#include <string>
#include <utility>
#include <Bank.h>
#include <memory>
#include <algorithm>
#include <iostream>



Bank::Bank(unsigned int bankId, std::__cxx11::basic_string<char> bankName, double bankFunds,
           std::__cxx11::basic_string<char> bankLocation) : bankID(bankId), bankName(std::move(bankName)),
                                                            bankFunds(bankFunds), bankLocation(std::move(bankLocation)) {}

unsigned int Bank::getBankId() const {
    return bankID;
}

const std::string &Bank::getBankName() const {
    return bankName;
}

double Bank::getBankFunds() const {
    return bankFunds;
}

const std::string &Bank::getBankLocation() const {
    return bankLocation;
}

std::shared_ptr<Client> Bank::createClient(const std::string pesel, const std::string name, const std::string surname,
                                               const std::string address, long phone, const std::string password) {

            std::shared_ptr<Client> newclient = std::make_shared<Client>(pesel, name, surname, address, phone,
                                                                         password);
            return newclient;
        }

std::shared_ptr<Loan> Bank::createLoan(const std::string clientPesel, double amount) {
    auto loan = std::make_shared<Loan>(clientPesel, amount);
    return loan;
}

void Bank::addClient(std::shared_ptr<Client> client) {
    clients.push_back(std::move(client));
}

void Bank::addAccount(std::shared_ptr<Account> account) {
    accounts.push_back(std::move(account));
}

unsigned int Bank::countClients(){
    return clients.size();
}

Bank::~Bank() = default;



void Bank::giveLoan(double amount,std::shared_ptr<Loan> l, std::shared_ptr<Account> account, int day, int month, int year, std::string purpose) {
    if (account->getBalance() >= (0.3 * amount))
    {
        l->setPurpose(purpose);
        l->setDay(day);
        l->setMonth(month);
        l->setYear(year);
        l->setDate(day, month, year);
        l->setClientPesel(account->getClientPesel());
       double m = account->getBalance();
        m += amount;
        account->setBalance(m);
      account->haveloan = true;
      bankFunds = bankFunds-amount;
      loans.push_back(l);
    }
    else{
        std::cout << "You don't have enough money" << std::endl;
        account->haveloan = false;
    }
}

void Bank::payOffLoan(double Amount, std::shared_ptr<Loan> l, std::shared_ptr<Account> account) {
    double a = l->getAmount();
    a= a - Amount;
    double b = account->getBalance();
    l->setAmount(a);
    account->setBalance(b-Amount);
   bankFunds+= a;
    if (a<=0)
    {
        loans.erase(std::remove(loans.begin(), loans.end(), l), loans.end());
        account->haveloan = false;
        std::cout << "You pay off the loan " << std::endl;

    }

}

const std::vector<std::shared_ptr<Client>> &Bank::getClients() const {
    return clients;
}

const std::vector<std::shared_ptr<Account>> &Bank::getAccounts() const {
    return accounts;
}

const std::vector<std::shared_ptr<Loan>> &Bank::getLoans() const {
    return loans;
}

std::shared_ptr<NormalAccount> Bank::createNormalAccount(int pin, double balance, std::string pesel, std::string accountNumber) {
    std::shared_ptr<NormalAccount> newaccount = std::make_shared<NormalAccount>(pin, balance, pesel, accountNumber);
    return newaccount;
}

std::shared_ptr<CreditAccount> Bank::createCreditAccount(int pin, double balance, std::string pesel, std::string accountNumber, double limit, float creditCost) {
    std::shared_ptr<CreditAccount> newaccount = std::make_shared<CreditAccount>(pin, balance, pesel, accountNumber, limit, creditCost);
    return newaccount;
}

std::shared_ptr<SavingsAccount> Bank::createSavingsAccount(int pin, double balance, std::string pesel, std::string accountNumber, float interestRate) {
    std::shared_ptr<SavingsAccount> newaccount = std::make_shared<SavingsAccount>(pin, balance, pesel, accountNumber, interestRate);
    return newaccount;
}

bool Bank::peselInUse(std::string pesel) {
    bool peselfound = false;
    for (auto &client: clients) {
        if (client->getClientPesel() == pesel) {
            peselfound = true;
        }
    }
    if (peselfound) {
        return true;
    } else {
        return false;
    }
}

bool Bank::checkPIN(std::string pesel, int PIN) {
    bool pinCorrect = false;
    for (const auto &account: accounts) {
        if (account->getClientPesel() == pesel) {
            if (account->getPin() == PIN) {
                pinCorrect = true;
            }
        }
    }
    if (pinCorrect) {
        return true;
    } else {
        return false;
    }
}

std::string Bank::generateAccountNumber() {
    int i;
    int x;
    int y;
    std::string s;
    srand(time(NULL));
    i =rand() % 10000;
    x = rand() % 10000;
    y = (i * x) % 100000;
    s = std::to_string(y);
    return s;
}







