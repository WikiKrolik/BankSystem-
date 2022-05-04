//
// Created by student on 1/21/22.
//

#ifndef FINALPROJECT_LOAN_H
#define FINALPROJECT_LOAN_H


#include <string>

class Loan {
private:
    int LoanID;
    std::string Purpose{""};
    int AccountID;
    int ClientID;
    double Amount;

public:

    void setAmount(double amount);

    std::string toString();

    int getLoanId() const;

    const std::string &getPurpose() const;

};


#endif //FINALPROJECT_LOAN_H
