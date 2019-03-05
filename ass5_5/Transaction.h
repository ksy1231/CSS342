//
// Created by SooYeon Kim on 5/26/2018.
//

#ifndef ASS5_7_TRANSACTION_H
#define ASS5_7_TRANSACTION_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#pragma once
using namespace std;
class Transaction
{
    friend fstream& operator >> (fstream &inf, Transaction &transaction);
    friend ostream& operator << (ostream &os, Transaction &transaction);

private:
    char action;
    int accountId;
    int otherAccountId;
    int fundId;
    int fundOtherId;
    int amount;
    string last;
    string first;
    bool fail;
public:
    Transaction();
    ~Transaction();

    char getAction() const;
    int getAcctId() const;
    int getOtherAccountId() const;
    int getFundId() const;
    int getOtherFundId() const;
    int getAmount() const;
    bool getFail() const;
    void setFail(bool fail);
    string getLast() const;
    string getFirst() const;
};

#endif //ASS5_7_TRANSACTION_H
