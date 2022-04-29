#ifndef _ACCOUNT_H
#define _ACCOUNT_H
#include <string>

class Account
{
private:
    int accID;
    int balance;
    std::string cusName;

public:
    Account(int id, int bal, std::string& name) : accID(id), balance(bal), cusName(name)
    {
    }
    int getaccID();
    int getbalance();
    void addmoney(int toadd);
    std::string getcusName();
};

#endif