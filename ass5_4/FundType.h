//
// Created by SooYeon Kim on 5/23/2018.
//

#ifndef ASS5_4_FUNDTYPE_H
#define ASS5_4_FUNDTYPE_H

#include "Transaction.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class FundType
{

    friend ostream& operator<<(ostream &outStream, const FundType &rhs);

public:
    FundType();
    FundType(string incFundName, int incBalance);
    ~FundType();

    string getFundName() const;
    int getBalance() const;
    bool isHistoryEmpty() const;
    void setFundName(const string& incFunName);
    void setBalance(const int& incBalance);
    void Deposit(const int &incAmount);
    void Withdraw(const int &incAmount);
    void AddHistory(const Transaction &incHistory);
    void DisplayHistory() const;

private:
    string fundName;
    int balance;
    vector<Transaction> history;
};

#endif //ASS5_4_FUNDTYPE_H
