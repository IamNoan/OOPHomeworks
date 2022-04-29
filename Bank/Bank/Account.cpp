#include "Account.h"
#include <string>

int Account::getaccID()
{
    return accID;
}

int Account::getbalance()
{
    return balance;
}

void Account::addmoney(int toadd)
{
    balance += toadd;
}

std::string Account::getcusName()
{
    return cusName;
}
