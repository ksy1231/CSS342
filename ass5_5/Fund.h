//
// Created by SooYeon Kim on 5/26/2018.
//

#ifndef ASS5_7_FUND_H
#define ASS5_7_FUND_H

#include <queue>
#include <iostream>
#include <string>
#pragma once
using namespace std;
class Fund
{
    friend ostream& operator << (ostream &os, const Fund &fund);
private:
    string name;
    int id;
    int balance;
    bool overdraft;
    queue<string> history;
    int coverageId;
    int historySize;
public:
    Fund();
    Fund(const string &name, const int &id, const int &amount);
    Fund(const string &name, const int &id, const int &amount, int idForCoverage);
    ~Fund();

    string getFundName() const;
    int getFundId() const;
    int getFundBalance() const;
    int getHistorySize() const;
    bool hasOverDraft() const;
    void AddHistory(const string &add);
    string getHistory() const;
    int getCoverageId() const;

    void AddAmount(const int &amount);
    int RemoveAmount(const int &amount);
};

#endif //ASS5_7_FUND_H
