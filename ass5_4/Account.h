//
// Created by SooYeon Kim on 5/23/2018.
//

#ifndef ASS5_4_ACCOUNT_H
#define ASS5_4_ACCOUNT_H

#include "FundType.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int TOTAL_TYPES_OF_FUND = 10;

class Account
{
    friend ostream& operator<<(ostream &outStream, const Account &rhs);

public:
    Account();
    Account(string incLastName, string incFirstName, int incId);
    ~Account();

    string getFirstName() const;
    string getLastName() const;
    int getID() const;
    FundType* getFund(const int &fundNum);
    int getFundBalance(int fundNum);
    void setFirstName(const string &incFirstName);
    void setLastName(const string &incLastName);
    void setID(const int &incID);
    void DisplayAllFund() const;
    void DisplayFund(const int &fund) const;

    bool operator==(const Account &rhs) const;
    bool operator!=(const Account &rhs) const;
    bool operator>(const Account &rhs) const;
    bool operator<(const Account &rhs) const;

private:
    string firstName;
    string lastName;
    int ID;
    FundType funds[TOTAL_TYPES_OF_FUND];
};

#endif //ASS5_4_ACCOUNT_H
