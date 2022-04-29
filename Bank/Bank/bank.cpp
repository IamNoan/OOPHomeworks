
#include <iostream>
#include "bank.h"
#include "Account.h"
using namespace std;

//Pointer of all accounts
Account* accounts[];
//Increment when a new account is created


void ShowMenu(void) {
    cout << "-----Menu------" << endl;
    cout << "1. Make account" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdrawal" << endl;
    cout << "4. Transfer" << endl;
    cout << "5. Display all" << endl; 
    cout << "6. Delete account" << endl;
    cout << "7. Delete all accounts" << endl;
    cout << "8. Exit program" << endl;
}

void MakeAccount(void) {
    int id;
    static int accNum = 0;
    std::string name;
    int balance;
    if (accNum >= MAX_ACC_NUM) {
        cout << "Sorry! cannot make an account anymore." << endl;
        return;
    }
    cout << "[Make Account]" << endl;
    cout << "Account ID: ";
    cin >> id;
    cout << "Customer Name: ";
    cin >> name;
    cout << "Deposit Amount: ";
    cin >> balance;
    cout << endl;
    if (GetAccIdx(id) != -1) {
        cout << "Error: Existing account ID" << endl;
        return;
    }

    Account newAcc (id,balance,name);
    accounts[accNum] = &newAcc;
    //accNum++;
}

void DepositMoney(void) {
    int money;
    int id;
    static int accNum = 0;
    cout << "[Deposit]" << endl;
    cout << "Account ID: ";
    cin >> id;
    cout << "Deposit amount: ";
    cin >> money;
    for (int i = 0; i < accNum; i++) {
        if (accounts[i]->getaccID() == id) {
            accounts[i]->addmoney(money);
            cout << "Deposit completed" << endl << endl;
            return;
        }
    }
    cout << "This ID is not valid." << endl << endl;
}

void WithdrawMoney(void) {
    static int accNum = 0;
    int money;
    int id;
    cout << "[Withdrawal]" << endl;
    cout << "Account ID: ";
    cin >> id;
    cout << "Withdrawal amount: ";
    cin >> money;

    for (int i = 0; i < accNum; i++) {
        if (accounts[i]->getaccID() == id) {
            if (accounts[i]->getbalance() < money) {
                cout << "Not enough balance" << endl << endl;
                return;
            }
            accounts[i]->addmoney(-money);
            cout << "Withdrawal completed" << endl << endl;
            return;
        }
    }
    cout << "This ID is not valid." << endl << endl;
}

void TransferMoney(void) {
    static int accNum = 0;
    int money;
    int sid;
    int rid;
    cout << "[Transfer]" << endl;
    cout << "Sender ID: ";
    cin >> sid;
    cout << "Receiver ID: ";
    cin >> rid;
    cout << "Transfer amount: ";
    cin >> money;

    for (int i = 0; i < accNum; i++) {
        if (accounts[i]->getaccID() == sid) {
            if (accounts[i]->getbalance() < money) {
                cout << "Not enough balance" << endl << endl;
                return;
            }
            //Sender account found and enough money
            //Loop to find the receiver
            for (int j = 0; j < accNum; j++)
            {
                if (accounts[j]->getaccID() == rid)
                {
                    accounts[i]->addmoney(-money);
                    accounts[j]->addmoney(money);
                    cout << "Transfer successfully completed" << endl << endl;
                    return;
                }
            }
            cout << "Receiver ID not found" << endl << endl;
            return;
        }
    }
    cout << "Sender ID not found" << endl << endl;
    return;
}

void ShowAllAccInfo(void) {
    static int accNum = 0;
    for (int i = 0; i < accNum; i++) {
        cout << "Account ID: " << accounts[i]->getaccID() << endl;
        cout << "Name: " << accounts[i]->getcusName() << endl;
        cout << "Balance: " << accounts[i]->getbalance() << endl;
    }
}

int GetAccIdx(int id) {
    static int accNum = 0;
    for (int i = 0; i < accNum; i++) {
        if (accounts[i]->getaccID() == id) {
            return i;
        }
    }
    return -1;
}

void DeleteBankAccount(void) {
    static int accNum = 0;
    int id;
    int index;
    cout << "[Delete Account]" << endl;
    cout << "Enter the ID of the account you want to delete : " << endl;
    cin >> id;
    //Gets the Index of the account
    index = GetAccIdx(id);
    if (index == -1)
    {
        //ID doesn't exist
        cout << "This account doesn't exists" << endl;
    }
    else
    {
        //Decrement number of accounts
        accNum--;
        //Replace the deleted account by the last account of the array that will be replaced when we create a new one
        accounts[index] = accounts[accNum];
        cout << "Account successfully deleted !" << endl;
    }
}

void DeleteAllAccounts(void) {
    static int accNum = 0;
    char answer;
    cout << "[Delete All Accounts]" << endl;
    cout << "!!! Are you sure you want to delete all the accounts ? (Y/N) !!!" << endl;
    cin >> answer;
    if (answer == 'Y')
    {
        //Just reset the accNum to rewrite accounts easier (accounts are still in the array but not usable)
        accNum = 0;
        cout << "All accounts deleted !" << endl;
    }
    else
    {
        cout << "No accounts deleted" << endl;
    }
}