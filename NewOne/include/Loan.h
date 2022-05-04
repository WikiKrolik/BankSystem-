#ifndef NEWONE_LOAN_H
#define NEWONE_LOAN_H

#include <string>
#include <memory>

class Loan{
private:
    int loanID;
    std::string purpose;
    std::string accountNumber;
    std::string clientPesel;
    double amount;
    int day;
    int month;
    int year;

public:

    Loan( std::string clientPesel, double amount);

    virtual ~Loan();

    const std::string &getClientPesel() const;

    double getAmount() const;

    int getDay() const;

    int getMonth() const;

    int getYear() const;

    void setPurpose(const std::string &purpose);

    void setClientPesel(const std::string &clientPesel);

    void setAmount(double Amount);

    void setDay(int d);

    void setMonth(int m);

    void setYear(int y);

    int setDate(int day, int month, int year);

    const std::string &getPurpose() const;

    double penalty();

};


#endif //NEWONE_LOAN_H
