//
// Created by SooYeon Kim on 5/23/2018.
//

#include "stdafx.h"
#include "Account.h"

Account::Account()
{
    firstName = "";
    lastName = "";
    ID = 0;
}

Account::Account(string incLastName, string incFirstName, int incID)
{
    lastName = incLastName;
    firstName = incFirstName;
    ID = incID;

    funds[0].setFundName("Money Market");
    funds[1].setFundName("Prime Money Market");
    funds[2].setFundName("Long-Term Bond");
    funds[3].setFundName("Short-Term Bond");
    funds[4].setFundName("500 Index Fund");
    funds[5].setFundName("Capital Value Fund");
    funds[6].setFundName("Growth Equity Fund");
    funds[7].setFundName("Growth Index Fund");
    funds[8].setFundName("Value Fund");
    funds[9].setFundName("Value Stock Index");
}

Account::~Account()
{
}

string Account::getFirstName() const
{
    return firstName;
}

string Account::getLastName() const
{
    return lastName;
}

int Account::getID() const
{
    return ID;
}

FundType* Account::getFund(const int &fundNum)
{
    return &funds[fundNum];
}

int Account::getFundBalance(int fundNum)
{
    return funds[fundNum].getBalance();
}

void Account::setFirstName(const string &incFName)
{
    firstName = incFName;
    return;
}

void Account::setLastName(const string &incLName)
{
    lastName = incLName;
    return;
}

void Account::setID(const int &incID)
{
    ID = incID;
    return;
}

void Account::DisplayAllFund() const
{
    cout << this->getFirstName() << " " << this->getLastName() << " Account ID: " << this->getID() << endl;
    cout << "    Money Market: $" << funds[0].getBalance() << endl;
    cout << "    Prime Money Market: $" << funds[1].getBalance() << endl;
    cout << "    Long-Term Bond: $" << funds[2].getBalance() << endl;
    cout << "    Short-Term Bond: $" << funds[3].getBalance() << endl;
    cout << "    500 Index Fund: $" << funds[4].getBalance() << endl;
    cout << "    Capital Value Fund: $" << funds[5].getBalance() << endl;
    cout << "    Growth Equity Fund: $" << funds[6].getBalance() << endl;
    cout << "    Growth Index Fund: $" << funds[7].getBalance() << endl;
    cout << "    Value Fund: $" << funds[8].getBalance() << endl;
    cout << "    Value Stock Index; $" << funds[9].getBalance() << endl;
    cout << endl;
}

void Account::DisplayFund(const int &incFundType) const
{
    switch (incFundType)
    {
        case 0:
            cout << "Money Market: " << funds[0].getBalance() << endl;
            break;
        case 1:
            cout << "Prime Money Market: " << funds[1].getBalance() << endl;
            break;
        case 2:
            cout << "Long-Term Bond: " << funds[2].getBalance() << endl;
            break;
        case 3:
            cout << "Short-Term Bond: " << funds[3].getBalance() << endl;
            break;
        case 4:
            cout << "500 Index Fund: " << funds[4].getBalance() << endl;
            break;
        case 5:
            cout << "Capital Value Fund: " << funds[5].getBalance() << endl;
            break;
        case 6:
            cout << "Growth Equity Fund: " << funds[6].getBalance() << endl;
            break;
        case 7:
            cout << "Growth Index Fund: " << funds[7].getBalance() << endl;
            break;
        case 8:
            cout << "Value Fund: " << funds[8].getBalance() << endl;
            break;
        case 9:
            cout << "Value Stock Index; " << funds[9].getBalance() << endl;
            break;
        default:
            cout << "Assinged Unknown Fund Type" << endl;
    }
}

ostream& operator<<(ostream &outStream, const Account &rhs)
{
    outStream << rhs.ID << ", " << rhs.firstName << ", " << rhs.lastName << endl;
    return outStream;
}

bool Account::operator==(const Account &rhs) const
{
    return ((this->ID) == (rhs.ID));
}

bool Account::operator!=(const Account &rhs) const
{
    return !(*this == rhs);
}

bool Account::operator>(const Account &rhs) const
{
    return ((this->ID) > (rhs.ID));
}

bool Account::operator<(const Account &rhs) const
{
    return ((this->ID) < (rhs.ID));
}
