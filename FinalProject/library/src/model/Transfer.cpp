
#include <model/Transfer.h>

Transfer::Transfer(int Amount, long long int AccountFrom, long long int AccountTo) {

}

Transfer::~Transfer() {

}

int Transfer::getAmount() {
    return Amount;
}

int Transfer::setAmount(int x) {
    Amount = x;
}
