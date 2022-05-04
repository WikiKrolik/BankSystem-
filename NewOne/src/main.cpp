#include <iostream>
#include "Interface.h"
#include "Bank.h"

int main()
{
    auto bank=std::make_shared<Bank>(1, "OOPBank", 15000000, "Warsaw");
    Interface interface(bank);
    interface.start();
}
