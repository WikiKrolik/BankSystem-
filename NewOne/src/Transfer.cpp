#include "Transfer.h"

Transfer::Transfer(const std::string &sourceAccountNumber, const std::string &destinationAccountNumber, double amount)
        : sourceAccountNumber(sourceAccountNumber), destinationAccountNumber(destinationAccountNumber),
          amount(amount) {}

void Transfer::makeTransfer(Account &sourceAccount, Account &destinationAccount) {
    if(!validateAccountNumbers(sourceAccount, destinationAccount)){
        throw std::exception();
    }
    if(!validateSourceBalance(sourceAccount)){
        throw std::exception();
    }
    sourceAccount.withdraw(amount);
    destinationAccount.deposit(amount);
}

bool Transfer::validateAccountNumbers(const Account &sourceAccount, const Account &destinationAccount) {
    return sourceAccount.accountNumber == sourceAccountNumber && destinationAccount.accountNumber == destinationAccountNumber;
}

bool Transfer::validateSourceBalance(const Account &sourceAccount) {
    return sourceAccount.canWithdraw(amount);
}