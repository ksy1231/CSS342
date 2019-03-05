//
// Created by SooYeon Kim on 5/26/2018.
//

#ifndef ASS5_7_BANK_H
#define ASS5_7_BANK_H

#include <fstream>
#include "BSTree.h"
#include "Transaction.h"
#include <queue>
#pragma once
class Bank
{
private:
    BSTree bankAccounts;
    queue<Transaction> theQueue;
    queue<string> history;
public:
    Bank();
    ~Bank();
    void buildQueue(string FileName);
    void useQueue();
};

#endif //ASS5_7_BANK_H
