#ifndef _BANK_H
#define _BANK_H

void ShowMenu(void);
void MakeAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void TransferMoney(void);
void ShowAllAccInfo(void);
int GetAccIdx(int);
void DeleteBankAccount(void);
void DeleteAllAccounts(void);
enum class bank { MAKE = 1, DEPOSIT, WITHDRAW,TRANSFER, INQUIRE, DELETE, DELETEALL , EXIT };
const int MAX_ACC_NUM = 100;

#endif
