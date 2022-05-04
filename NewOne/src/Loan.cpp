#include <iostream>
#include "Loan.h"
#include <ctime>


Loan::Loan(std::string ClientPesel, double amount) : clientPesel(ClientPesel), amount(amount){

}

Loan::~Loan() {

}


double Loan::getAmount() const {
    return amount;
}

int Loan::getDay() const {
    return day;
}

int Loan::getMonth() const {
    return month;
}

int Loan::getYear() const {
    return year;
}

void Loan::setPurpose(const std::string &Purpose) {
    purpose = Purpose;
}


void Loan::setAmount(double Amount) {
    amount = Amount;
}

void Loan::setDay(int d) {
    day = d;
}

void Loan::setMonth(int m) {
    month = m;
}

void Loan::setYear(int y) {
    year = y;
}

int Loan::setDate(int day, int month, int year) {
    int d=getDay();
    int m=getMonth();
    int y=getYear();
    return d, m, y;

}


const std::string &Loan::getClientPesel() const {
    return clientPesel;
}



double Loan::penalty()
{
    time_t my_time = time(0);

    tm* now = localtime(&my_time);

    if(now->tm_year+1900 >= getYear() &&  now->tm_mon+1 >= getMonth() && now->tm_mday > getDay())
    {
        amount = amount * 1.1;
        if ( getMonth()<12)
            setMonth(getMonth()+1);
        else {
            setMonth(1);
            setYear(getYear() + 1);
        }

        return amount;
    }


}

const std::string &Loan::getPurpose() const {
    return purpose;
}

void Loan::setClientPesel(const std::string &clientPesel) {
    Loan::clientPesel = clientPesel;
}



