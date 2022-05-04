#include <stdexcept>
#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(int pin, double balance, const std::string &clientPesel,
                               const std::string &accountNumber, float interestRate) : Account(pin,
                                                                                               balance,
                                                                                               clientPesel,
                                                                                               accountNumber),
                                                                                       interestRate(
                                                                                                             interestRate){}

bool SavingsAccount::canWithdraw(double amount) const {
    return amount <= balance;
}

void SavingsAccount::withdraw(double amount) {
    if(canWithdraw(amount)) {
        balance -= amount;
    }
}

float SavingsAccount::getInterestRate() {
    return interestRate;
}
