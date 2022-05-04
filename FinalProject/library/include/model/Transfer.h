#ifndef FINALPROJECT_TRANSFER_H
#define FINALPROJECT_TRANSFER_H

class Transfer{
private:
    int Amount;
public:
    long long int AccountFrom;
    long long int AccountTo;

    Transfer(int Amount, long long int AccountFrom, long long int AccountTo);
    ~Transfer();
    int getAmount();
    int setAmount(int x);
};
#endif