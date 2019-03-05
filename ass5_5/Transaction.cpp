//
// Created by SooYeon Kim on 5/26/2018.
//

#include "stdafx.h"
#include "Transaction.h"


Transaction::Transaction() : action(' '), accountId(-1), fundId(-1), amount(-1), fundOtherId(-1), otherAccountId(-1), fail(false)
{
}





Transaction::~Transaction()
{
}


char Transaction::getAction() const
{
    return action;
}

int Transaction::getAcctId() const
{
    return accountId;
}

int Transaction::getOtherAccountId() const
{
    return otherAccountId;
}

int Transaction::getFundId() const
{
    return fundId;
}

int Transaction::getOtherFundId() const
{
    return fundOtherId;
}

bool Transaction::getFail() const
{
    return fail;
}

int Transaction::getAmount() const
{
    return amount;
}

string Transaction::getLast() const
{
    return last;
}
void Transaction::setFail(bool f)
{
    fail = f;
}

string Transaction::getFirst() const
{
    return first;
}

fstream& operator >> (fstream &inFile, Transaction &transaction)
{

    if (inFile.peek() == 'O')
    {

        vector<char> f;
        vector<char> l;

        inFile >> transaction.action;
        inFile.ignore(1);
        while (inFile.peek() != ' ')
        {
            l.push_back(inFile.peek());
            inFile.ignore(1);
        }
        inFile.ignore(1);
        while (inFile.peek() != ' ')
        {

            f.push_back(inFile.peek());
            inFile.ignore(1);
        }

        for (int i = 0; i < f.size(); i++)
        {
            transaction.first += f[i];
        }
        for (int i = 0; i < l.size(); i++)
        {
            transaction.last += l[i];
        }
        inFile >> transaction.accountId;

    }
    else if (inFile.peek() == 'T')
    {
        inFile >> transaction.action;
        inFile >> transaction.accountId;
        transaction.fundId = transaction.accountId % 10;
        transaction.accountId /= 10;
        inFile >> transaction.amount;
        inFile >> transaction.otherAccountId;
        transaction.fundOtherId = transaction.otherAccountId % 10;
        transaction.otherAccountId /= 10;
        if (transaction.accountId < 1000 || transaction.accountId > 99999 || transaction.otherAccountId < 1000 || transaction.otherAccountId > 9999)
        {
            transaction.setFail(true);
        }
    }
    else if (inFile.peek() == 'H')
    {
        inFile >> transaction.action;
        inFile >> transaction.accountId;
        if (transaction.accountId < 1000 || transaction.accountId > 99999)
        {
            transaction.setFail(true);
        }
        else if (transaction.accountId < 10000)
        {
            transaction.fundOtherId = 10;
        }
        else
        {
            transaction.fundId = transaction.accountId % 10;
            transaction.accountId /= 10;
            if (transaction.fundId < 0)
            {
                transaction.setFail(true);
            }
        }
    }
    else if (inFile.peek() == 'D')
    {
        inFile >> transaction.action;
        inFile >> transaction.accountId;
        transaction.fundId = transaction.accountId % 10;
        transaction.accountId /= 10;
        if (transaction.accountId < 1000 || transaction.accountId > 9999)
        {
            transaction.setFail(true);
        }
        inFile >> transaction.amount;
    }
    else if (inFile.peek() == 'W')
    {
        inFile >> transaction.action;
        inFile >> transaction.accountId;
        transaction.fundId = transaction.accountId % 10;
        transaction.accountId /= 10;
        inFile >> transaction.amount;
    }
    else
    {
        transaction.setFail(true);
    }
    inFile.ignore(1);

    return inFile;
}

ostream& operator << (ostream& os, Transaction &transaction)
{
    cout << transaction.action << " ";
    if (transaction.action != 'O')
    {
        cout << transaction.accountId;
    }
    else
    {
        cout << transaction.first << " " << transaction.last << " " << transaction.accountId;
    }
    if (transaction.action != 'O' && transaction.fundOtherId != 10)
    {
        cout << transaction.fundId;
    }
    if (transaction.action != 'H' && transaction.action != 'O')
    {
        cout << " $" << transaction.amount;
    }
    if (transaction.action == 'T')
    {
        cout << " " << transaction.accountId << transaction.fundOtherId;
    }
    if (transaction.getFail() == true)
    {
        cout << "   (fail)";
    }
    return os;
}
