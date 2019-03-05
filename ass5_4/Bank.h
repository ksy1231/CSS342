//
// Created by SooYeon Kim on 5/23/2018.
//

#ifndef ASS5_4_BANK_H
#define ASS5_4_BANK_H

#include "BSTree.h"
#include "Account.h"
#include "Transaction.h"
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;
class Bank
{
public:
    Bank();
    ~Bank();

    void ReadTxtFile(string fileName);
    void ProceedQue();
    void DisplayAllAccount() const;

private:
    queue<Transaction> requestList;
    BSTree acctInfoTree;
    bool openAccount(Transaction &incTransaction);
    bool deposit(Transaction &incTransaction);
    bool withdraw(Transaction &incTransaction);
    bool transfer(Transaction &incTransaction);
    bool history(Transaction &incTransaction);

};

#endif //ASS5_4_BANK_H
