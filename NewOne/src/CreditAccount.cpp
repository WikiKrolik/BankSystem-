#include <stdexcept>
#include "CreditAccount.h"

CreditAccount::CreditAccount(int pin, double balance, const std::string &clientPesel, const std::string &accountNumber,
                             double limit, float creditCost) : Account(pin, balance, clientPesel, accountNumber),
                                                               limit(limit) {}

bool CreditAccount::canWithdraw(double amount) const {
    return amount <= balance + limit;
}

void CreditAccount::withdraw(double amount) {
    if(canWithdraw(amount)){
        balance -= amount;
    }
}

double CreditAccount::getLimit() {
    return limit;
}
