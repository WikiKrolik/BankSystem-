#ifndef NEWONE_INTERFACE_H
#define NEWONE_INTERFACE_H
#include <memory>
#include "Bank.h"

class Interface {
private:
    std::shared_ptr<Bank> bank;

public:
    explicit Interface(const std::shared_ptr<Bank> &bank);

    virtual ~Interface();

    void start();

    void login();

    void registerClient();

    void deleteClient();

    void listClients();

    void logged(std::string pesel);

    void createNormal(std::string pesel);

    void createCredit(std::string pesel);

    void createSavings(std::string pesel);

    void openAccount(std::string pesel);

    void accountPanel(std::string pesel);

    void accountOptions(std::string pesel);

    void depositInterface(std::string pesel);

    void withdrawInterface(std::string pesel);

    void transferInterface(std::string pesel);

    void loanInterface(std::string pesel);
};

#endif //NEWONE_INTERFACE_H
