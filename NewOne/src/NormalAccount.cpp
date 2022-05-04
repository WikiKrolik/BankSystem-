#include <stdexcept>
#include "NormalAccount.h"

bool NormalAccount::canWithdraw(double amount) const {
    return amount <= balance;
}

void NormalAccount::withdraw(double amount) {
    if(canWithdraw(amount)) {
        balance -= amount;
    }
}

NormalAccount::NormalAccount(int pin, double balance, const std::string &clientPesel, const std::string &accountNumber)
        : Account(pin, balance, clientPesel, accountNumber) {}
