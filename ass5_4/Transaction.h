//
// Created by SooYeon Kim on 5/23/2018.
//

#ifndef ASS5_4_TRANSACTION_H
#define ASS5_4_TRANSACTION_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Transaction
{
    friend ostream &operator<<(ostream &outStream, const Transaction &rhs);
    friend istream &operator>>(istream &inStream, Transaction &rhs);

public:
    Transaction();
    ~Transaction();

    string getTransactionType() const;
    string getFirstName() const;
    string getLastName() const;
    int getMainAcctID() const;
    int getSecondAcctID() const;
    int getMainFundTypeID() const;
    int getSecondFundTypeID() const;
    int getAmount() const;
    bool getValidTrans() const;

    void setTransactionType(const string &incType);
    void setFirstName(const string &incFirstName);
    void setLastName(const string &incLastName);
    void setMainAcctID(const int &incAcctID);
    void setSecondAcctID(const int &incAcctID);
    void setMainFundTypeID(const int &incFundID);
    void setSecondFundTypeID(const int &incFundID);
    void setAmount(const int &incAmount);
    void setValidTrans(const bool &incFact);

private:
    string transactionType;
    string firstName;
    string lastName;
    int mainAcctID;
    int secondAcctID;
    int mainFundTypeID;
    int secondFundTypeID;
    int amount;
    bool validTrans;
};

#endif //ASS5_4_TRANSACTION_H
