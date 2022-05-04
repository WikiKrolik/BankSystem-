//
// Created by student on 1/21/22.
//

#include "model/Loan.h"

void Loan::setAmount(double amount) {
    Amount = amount;
}

int Loan::getLoanId() const {
    return LoanID;
}

const std::string &Loan::getPurpose() const {
    return Purpose;
}
