#include <iostream>
#include "bank.h"

using namespace std;
int main(void) {
    int choice;

    while (1) {
        ShowMenu();
        cout << "Select Menu: ";
        cin >> choice;
        cout << endl;

        switch (bank(choice)) {
        case bank::MAKE:
            MakeAccount();
            break;
        case bank::DEPOSIT:
            DepositMoney();
            break;
        case bank::WITHDRAW:
            WithdrawMoney();
            break;
        case bank::TRANSFER:
            TransferMoney();
            break;
        case bank::INQUIRE:
            ShowAllAccInfo();
            break;
        case bank::DELETE:
            DeleteBankAccount();
            break;
        case bank::DELETEALL:
            DeleteAllAccounts();
            break;
        case bank::EXIT:
            return 0;
         
        default:
            cout << "Illegal Selection.." << endl;
        }
    }
    return 0;
}