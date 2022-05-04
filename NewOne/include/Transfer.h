//
// Created by student on 2/3/22.
//

#ifndef NEWONE_TRANSFER_H
#define NEWONE_TRANSFER_H

#include "Account.h"

class Transfer {
private:
    std::string sourceAccountNumber;
    std::string destinationAccountNumber;
    double amount;
public:
    Transfer(const std::string &sourceAccountNumber, const std::string &destinationAccountNumber, double amount);

    void makeTransfer(Account& sourceAccount, Account& destinationAccount);

private:
    bool validateAccountNumbers(const Account& sourceAccount, const Account& destinationAccount);

    bool validateSourceBalance(const Account& sourceAccount);
};


#endif //NEWONE_TRANSFER_H
