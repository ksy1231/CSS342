//
// Created by SooYeon Kim on 5/26/2018.
//

#include "stdafx.h"
#include "Fund.h"


Fund::Fund() : name(""), id(-1), balance(-1), overdraft(false), coverageId(-1)
{
}
Fund::Fund(const string &name, const int &id, const int &amount) : name(name), id(id), balance(amount), overdraft(false), coverageId(-1)
{
}

Fund::Fund(const string &name, const int &id, const int &amount, int idForCoverage) : name(name), id(id), balance(amount), overdraft(true), coverageId(idForCoverage)
{

}

Fund::~Fund()
{
}

string Fund::getFundName() const
{
    return name;
}

int Fund::getFundId() const
{
    return id;
}

int Fund::getFundBalance() const
{
    return balance;
}

void Fund::AddHistory(const string &add)
{
    history.push(add);
}

bool Fund::hasOverDraft() const
{
    return overdraft;
}

string Fund::getHistory() const
{
    queue<string> temp(history);
    string result = "";

    while (!temp.empty())
    {
        result += temp.front() + "\n";
        temp.pop();
    }

    return result;
}

void Fund::AddAmount(const int &amount)
{
    balance += amount;
}

int Fund::RemoveAmount(const int &amount)
{
    balance -= amount;
    return amount;
}

int Fund::getCoverageId() const
{
    return coverageId;
}

int Fund::getHistorySize() const
{
    return history.size();
}

ostream& operator << (ostream &os, const Fund &fund)
{
    cout << fund.name << ":  $" << fund.balance << endl;
    return os;
}
