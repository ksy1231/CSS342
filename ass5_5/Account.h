//
// Created by SooYeon Kim on 5/26/2018.
//

#ifndef ASS5_7_ACCOUNT_H
#define ASS5_7_ACCOUNT_H

#include "Client.h"
#include "Fund.h"
#include "Transaction.h"
#include <vector>
#include <queue>
#pragma once
using namespace std;
class Account
{
    friend ostream& operator << (ostream &os, Account &acct);
private:
    Client accountHolder;

    Fund money_Market;
    Fund prime_Money_Market;
    Fund long_Term_Bond;
    Fund short_Term_Bond;
    Fund five_Hundred_Index_Fund;
    Fund capital_Value_Fund;
    Fund growth_Equity_Fund;
    Fund growth_Index_Fund;
    Fund value_Fund;
    Fund value_Stock_Index;
    vector<Fund> funds;

    queue<Transaction> history;

    queue<string> errors;

    int accountId;
public:
    Account();
    Account(const string &last, const string &first, const int &id);
    ~Account();

    int getId() const;

    void GetHistory() const;
    void AddHistory(Transaction transaction);
    void determineAction(Transaction transaction);
    void Deposit(const int &amount, const int &fundId);
    void Withdraw(const int &amount, const int &fundId);
    void Transfer(const int &amount, const int &idFrom, Account* to, const int &idTo);
    void History(const int &fundId) const;
    void ErrorHistory();
};

#endif //ASS5_7_ACCOUNT_H
