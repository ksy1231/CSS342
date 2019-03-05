//
// Created by SooYeon Kim on 5/23/2018.
//

#include "stdafx.h"
#include "FundType.h"


FundType::FundType()
{
    fundName = "";
    balance = 0;
}

FundType::FundType(string incFundName, int incBalance)
{
    fundName = incFundName;
    balance = incBalance;
}

FundType::~FundType()
{
}

string FundType::getFundName() const
{
    return fundName;
}

int FundType::getBalance() const
{
    return balance;
}

void FundType::setFundName(const string& incFunName)
{
    fundName = incFunName;
    return;
}

void FundType::setBalance(const int& incBalance)
{
    balance = incBalance;
    return;
}

void FundType::Deposit(const int &incAmount)
{
    balance += incAmount;
    return;
}

void FundType::Withdraw(const int &incAmount)
{
    balance -= incAmount;
    return;
}

void FundType::AddHistory(const Transaction &incTransaction)
{
    history.push_back(incTransaction);
    return;
}

void FundType::DisplayHistory() const
{
    for (int i = 0; i < history.size(); i++)
    {
        cout << "  " << history[i];
        if (history[i].getValidTrans() == false)
        {
            cout << " (Failed)";
        }
        cout << endl;
    }
    return;
}

bool FundType::isHistoryEmpty() const
{
    return !(history.size() > 0);
}

ostream& operator<<(ostream &outStream, const FundType &rhs)
{
    outStream << rhs.getFundName() << ": $" << rhs.getBalance();
    return outStream;
}

