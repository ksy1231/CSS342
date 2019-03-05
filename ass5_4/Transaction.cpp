//
// Created by SooYeon Kim on 5/23/2018.
//

#include "stdafx.h"
#include "Transaction.h"

Transaction::Transaction()
{
    transactionType = "";
    firstName = "";
    lastName = "";
    amount = 0;
    mainAcctID = 0;
    secondAcctID = 0;
    mainFundTypeID = 0;
    secondFundTypeID = 0;
    validTrans = true;
}

Transaction::~Transaction()
{
}

string Transaction::getTransactionType() const
{
    return transactionType;
}

string Transaction::getFirstName() const
{
    return firstName;
}

string Transaction::getLastName() const
{
    return lastName;
}

int Transaction::getMainAcctID() const
{
    return mainAcctID;
}

int Transaction::getSecondAcctID() const
{
    return secondAcctID;
}

int Transaction::getMainFundTypeID() const
{
    return mainFundTypeID;
}

int Transaction::getSecondFundTypeID() const
{
    return secondFundTypeID;
}

int Transaction::getAmount() const
{
    return amount;
}

bool Transaction::getValidTrans() const
{
    return validTrans;
}

void Transaction::setTransactionType(const string &incType)
{
    transactionType = incType;
    return;
}

void Transaction::setFirstName(const string &incFirstName)
{
    firstName = incFirstName;
    return;
}

void Transaction::setLastName(const string &incLastName)
{
    lastName = incLastName;
    return;
}

void Transaction::setMainAcctID(const int &incAcctID)
{
    mainAcctID = incAcctID;
    return;
}

void Transaction::setSecondAcctID(const int &incAcctID)
{
    secondAcctID = incAcctID;
    return;
}

void Transaction::setMainFundTypeID(const int &incFundID)
{
    mainFundTypeID = incFundID;
    return;
}

void Transaction::setSecondFundTypeID(const int &incFundID)
{
    secondFundTypeID = incFundID;
    return;
}

void Transaction::setAmount(const int &incAmount)
{
    amount = incAmount;
    return;
}

void Transaction::setValidTrans(const bool &incFact)
{
    validTrans = incFact;
    return;
}

ostream &operator<<(ostream &outStream, const Transaction &rhs)
{
    if (rhs.getTransactionType() == "D" || rhs.getTransactionType() == "W")
    {
        outStream << rhs.getTransactionType() << " " << rhs.getMainAcctID() << rhs.getMainFundTypeID() << " " << rhs.getAmount();
    }
    else if (rhs.getTransactionType() == "T")
    {
        outStream << "T " << rhs.getMainAcctID() << rhs.getMainFundTypeID() << " " << rhs.getAmount() << " "
                  << rhs.getSecondAcctID() << rhs.getSecondFundTypeID();
    }

    return outStream;
}

istream &operator>>(istream &inStream, Transaction &rhs)
{
    string newTranType;
    inStream >> newTranType;
    rhs.transactionType = newTranType;
    int fromAcctID = 0;
    int toAcctID = 0;

    if (newTranType == "O")
    {
        inStream >> rhs.lastName >> rhs.firstName >> rhs.mainAcctID;
    }
    else if (newTranType == "D" || newTranType == "W")
    {
        inStream >> fromAcctID >> rhs.amount;

        if (fromAcctID >= 10000 && fromAcctID <= 99999)
        {
            rhs.mainAcctID = fromAcctID / 10;
            rhs.mainFundTypeID = fromAcctID % 10;
        }
        else
        {
            rhs.mainAcctID = fromAcctID;
            rhs.mainFundTypeID = -1;
        }
    }
    else if (newTranType == "T")
    {
        inStream >> fromAcctID >> rhs.amount >> toAcctID;

        if (fromAcctID >= 10000 && fromAcctID <= 99999)
        {
            rhs.mainAcctID = fromAcctID / 10;
            rhs.mainFundTypeID = fromAcctID % 10;
        }
        else
        {
            rhs.mainAcctID = fromAcctID;
            rhs.mainFundTypeID = -1;
        }

        if (toAcctID >= 10000 && toAcctID <= 99999)
        {
            rhs.secondAcctID = toAcctID / 10;
            rhs.secondFundTypeID = toAcctID % 10;
        }
        else
        {
            rhs.secondAcctID = toAcctID;
            rhs.mainFundTypeID = -1;
        }
    }
    else if (newTranType == "H")
    {
        inStream >> fromAcctID;

        if (fromAcctID >= 10000 && fromAcctID <= 99999)
        {
            rhs.mainAcctID = fromAcctID / 10;
            rhs.mainFundTypeID = fromAcctID % 10;
        }
        else
        {
            rhs.mainAcctID = fromAcctID;
            rhs.mainFundTypeID = -1;
        }
    }
    return inStream;
}
