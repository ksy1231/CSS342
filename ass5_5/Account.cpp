//
// Created by SooYeon Kim on 5/26/2018.
//

#include "stdafx.h"
#include "Account.h"

//Initializes account holder and all funds, then places the funds appropriately into the vector of Fund.
Account::Account(const string &first, const string &last, const int &id) : accountHolder(first, last), accountId(id), money_Market("Money Market", 0, 0, 1), prime_Money_Market("Prime Money Market", 1, 0, 0), long_Term_Bond("Long-Term Bond", 2, 0, 3),
                                                                           short_Term_Bond("Short-Term Bond", 3, 0, 2), five_Hundred_Index_Fund("500 Index Fund", 4, 0), capital_Value_Fund("Capital Value Fund", 5, 0), growth_Equity_Fund("Growth Equity Fund", 6, 0), growth_Index_Fund("Growth Index Fund", 7, 0),
                                                                           value_Fund("Value Fund", 8, 0), value_Stock_Index("Value Stock Index", 9, 0)
{
    funds.push_back(money_Market);
    funds.push_back(prime_Money_Market);
    funds.push_back(long_Term_Bond);
    funds.push_back(short_Term_Bond);
    funds.push_back(five_Hundred_Index_Fund);
    funds.push_back(capital_Value_Fund);
    funds.push_back(growth_Equity_Fund);
    funds.push_back(growth_Index_Fund);
    funds.push_back(value_Fund);
    funds.push_back(value_Stock_Index);
}

Account::Account() : accountHolder("", ""), accountId(-1)
{
}

Account::~Account()
{
}

int Account::getId() const
{
    return accountId;
}

void Account::AddHistory(Transaction action)
{
    history.push(action);
}

void Account::GetHistory() const
{
    queue<Transaction> temp(history);
    while (temp.size() > 0)
    {
        cout << "   " << temp.front() << endl;
        temp.pop();
    }
}

void Account::determineAction(Transaction action)
{
    char d = action.getAction();
    switch (d)
    {
        case 'D':
            if (action.getAmount() < 0)
            {
                action.setFail(true);
                string history = "   D " + to_string(accountId) + to_string(action.getFundId()) + " $" + to_string(action.getAmount()) + " (failed)";
                funds[action.getFundId()].AddHistory(history);
                Deposit(action.getAmount(), action.getFundId());
                break;
            }
            else
            {
                Deposit(action.getAmount(), action.getFundId());
                break;
            }
        case 'W':
            if (action.getAmount() < 0|| (funds[action.getFundId()].getFundBalance() - action.getAmount() < 0 && !funds[action.getFundId()].hasOverDraft()))
            {
                action.setFail(true);
                string history = "   W " + to_string(accountId) + to_string(action.getFundId()) + " $" + to_string(action.getAmount()) + " (failed)";
                funds[action.getFundId()].AddHistory(history);
                Withdraw(action.getAmount(), action.getFundId());
                break;
            }
            else
            {
                Withdraw(action.getAmount(), action.getFundId());
                break;
            }
        case 'T':
            if (action.getAmount() < 0 || !funds[action.getFundId()].hasOverDraft() && funds[action.getFundId()].getFundBalance() - action.getAmount() < 0)
            {
                action.setFail(true);
                string history = "   T " + to_string(accountId) + to_string(action.getFundId()) + " $" + to_string(action.getAmount()) + " " + to_string(accountId) + to_string(action.getOtherFundId()) + " (failed)";
                funds[action.getFundId()].AddHistory(history);
                if (action.getOtherFundId() >= 0 && action.getOtherFundId() < 10)
                {
                    funds[action.getOtherFundId()].AddHistory(history);
                }
                Transfer(action.getAmount(), action.getFundId(), this, action.getOtherFundId());
                break;
            }
            else if (action.getFundId() == action.getOtherFundId())
            {
                action.setFail(true);
                string history = "   T " + to_string(accountId) + to_string(action.getFundId()) + " $" + to_string(action.getAmount()) + " " + to_string(accountId) + to_string(action.getOtherFundId()) + " (failed)";
                funds[action.getFundId()].AddHistory(history);
                string h("ERROR: CANNOT TRANSFER FROM A FUND TO ITSELF");
                errors.push(h);
                cerr << h << endl;
                break;
            }
            else
            {
                if (funds[action.getFundId()].hasOverDraft() && funds[action.getFundId()].getFundBalance() < action.getAmount())
                {
                    int x = funds[action.getFundId()].getCoverageId();
                    if (action.getOtherFundId() == funds[action.getFundId()].getCoverageId() && funds[action.getFundId()].getFundBalance() < action.getAmount() ||funds[action.getFundId()].getFundBalance() + funds[x].getFundBalance() < action.getAmount())
                    {
                        action.setFail(true);
                        string history = "   T " + to_string(accountId) + to_string(action.getFundId()) + " $" + to_string(action.getAmount()) + " " + to_string(accountId) + to_string(action.getOtherFundId()) + " (failed)";
                        funds[action.getFundId()].AddHistory(history);
                        if (action.getOtherFundId() >= 0 && action.getOtherFundId() < 10 && action.getFundId() != action.getOtherFundId())
                        {
                            funds[action.getOtherFundId()].AddHistory(history);
                        }
                    }
                }
                Transfer(action.getAmount(), action.getFundId(), this, action.getOtherFundId());
                break;
            }
        case 'H':
            if (action.getFail() == true)
            {
                if (action.getOtherFundId() == 10)
                {
                    AddHistory(action);
                    string h("ERROR: CANNOT PRINT HISTORY FOR ACCOUNT " + to_string(action.getAcctId()) + ", INVALID ACCOUNT ID");
                    errors.push(h);
                    cerr << h << endl;
                    break;
                }
                else if (action.getFundId() >= 0 && action.getFundId() <= 9)
                {
                    string history = "   H " + to_string(accountId) + to_string(action.getFundId());
                    funds[action.getFundId()].AddHistory(history);
                    string h("ERROR: CANNOT PRINT HISTORY FOR ACCOUNT " + to_string(action.getAcctId()) + ", INVALID ID");
                    errors.push(h);
                    cerr << h << endl;
                    break;
                }
                else
                {
                    string history = "   H " + to_string(accountId) + to_string(action.getFundId());
                    string h("ERROR: CANNOT PRINT HISTORY FOR ACCOUNT " + to_string(action.getAcctId()) + ", INVALID ID");
                    errors.push(h);
                    cerr << h << endl;
                }
            }
            else
            {
                if (action.getOtherFundId() == 10)
                {
                    AddHistory(action);
                    History(action.getOtherFundId());
                    break;
                }
                else
                {
                    string history = "   H " + to_string(accountId) + to_string(action.getFundId());
                    funds[action.getFundId()].AddHistory(history);
                    History(action.getFundId());
                    break;
                }
            }

    }

}

void Account::Deposit(const int &amount, const int &fundId)
{
    if (amount < 0)
    {
        if (fundId > 9 || fundId < 0)
        {
            string h("ERROR: COULD NOT DEPOSIT $" + to_string(amount) + " INTO FUND " + to_string(fundId) + ", AMOUNT MUST BE POSITIVE AND FUND ID MUST BE VALID\n");
            errors.push(h);
            cerr << h;
        }
        else
        {
            string h("ERROR: COULD NOT DEPOSIT $" + to_string(amount) + " INTO FUND " + to_string(fundId) + ", AMOUNT MUST BE POSITIVE\n");
            errors.push(h);
            cerr << h;
        }
        return;
    }
    else if (fundId > 9 || fundId < 0)
    {
        string h("ERROR: COULD NOT DEPOSIT $" + to_string(amount) + " INTO FUND " + to_string(fundId) + ", FUND ID MUST BE VALID\n");
        errors.push(h);
        cerr << h;
    }
    else
    {
        funds[fundId].AddAmount(amount);
        string history = "   D " + to_string(accountId) + to_string(fundId) + " $" + to_string(amount);
        funds[fundId].AddHistory(history);
    }
}

void Account::Withdraw(const int &amount, const int &fundId)
{

    if (amount < 0)
    {
        if (fundId > 9 || fundId < 0)
        {
            string h("ERROR: COULD NOT WITHDRAW $" + to_string(amount) + " FROM FUND " + to_string(fundId) + ", AMOUNT MUST BE POSITIVE AND FUND ID MUST BE VALID\n");
            errors.push(h);
            cerr << h;
            return;
        }
        else
        {
            string h("\nERROR: COULD NOT WITHDRAW $" + to_string(amount) + " FROM FUND " + to_string(fundId) + ", AMOUNT MUST BE POSITIVE\n");
            errors.push(h);
            cerr << h;
            return;
        }

    }
    else if (funds[fundId].getFundBalance() == 0 || funds[fundId].getFundBalance() - amount < 0)
    {
        bool draft = funds[fundId].hasOverDraft();
        int cover = funds[fundId].getCoverageId();
        switch (draft)
        {
            case (true) :
                if (funds[fundId].getFundBalance() + funds[cover].getFundBalance() < amount)
                {
                    string history = "   W " + to_string(accountId) + to_string(fundId) + " $" + to_string(amount) + " (failed)";
                    funds[fundId].AddHistory(history);
                    string h("ERROR: COULD NOT WITHDRAW $" + to_string(amount) + " FROM FUND " + to_string(fundId) + ", INSUFFICIENT FUNDS IN BOTH FUND" +
                             "           " + to_string(fundId) + " AND ITS OVERDRAFT FUND " + to_string(funds[fundId].getCoverageId() + '\n'));
                    errors.push(h);
                    cerr << h;
                    break;
                }
                else
                {
                    int forCover = -1 * (funds[fundId].getFundBalance() - amount);
                    funds[cover].RemoveAmount(forCover);
                    funds[fundId].RemoveAmount(funds[fundId].getFundBalance());
                    string historyCover = "   W " + to_string(accountId) + to_string(cover) + " $" + to_string(forCover);
                    string history = "   W " + to_string(accountId) + to_string(fundId) + " $" + to_string(amount - forCover);
                    funds[cover].AddHistory(historyCover);
                    funds[fundId].AddHistory(history);
                    break;
                }
            case(false) :
                string history = "   W " + to_string(accountId) + to_string(fundId) + " $" + to_string(amount) + " (failed)";
                string h("ERROR: COULD NOT WITHDRAW $" + to_string(amount) + " FROM FUND " + to_string(fundId) + ", INSUFFICIENT FUNDS\n");
                errors.push(h);
                cerr << h;
                break;
        }
    }
    else
    {
        funds[fundId].RemoveAmount(amount);
        string history = "   W " + to_string(accountId) + to_string(fundId) + " $" + to_string(amount);
        funds[fundId].AddHistory(history);
    }
}

void Account::Transfer(const int &amount, const int &idFrom, Account *to, const int &idTo)
{
    if (amount < 0)
    {
        if (idFrom > 9 || idFrom < 0 || idTo > 9 || idTo < 0)
        {
            string h("ERROR: COULD NOT TRANSFER $" + to_string(amount) + " FROM FUND " + to_string(idFrom) + " TO FUND " + to_string(idTo) + ", AMOUNT MUST BE POSITIVE AND BOTH FUND IDS MUST BE VALID\n");
            errors.push(h);
            cerr << h;
        }
        {
            string h("ERROR: COULD NOT TRANSFER $" + to_string(amount) + " FROM FUND " + to_string(idFrom) + " TO FUND " + to_string(idTo) + ", AMOUNT MUST BE POSITIVE\n");
            errors.push(h);
            cerr << h;
        }
    }
    else if (funds[idFrom].getCoverageId() == idTo && this->getId() == to->getId())
    {
        if (funds[idFrom].getFundBalance() < amount)
        {
            string h("ERROR: COULD NOT TRANSFER $" + to_string(amount) + " FROM FUND " + to_string(idFrom) + " TO OVERDRAFT FUND " + to_string(idTo) + ", INSUFFICIENT " +
                     "          FUNDS\n");
            errors.push(h);
            cerr << h;
        }
        else if (funds[idFrom].getFundBalance() == 0)
        {
            string history = "   T " + to_string(accountId) + to_string(idFrom) + " $" + to_string(amount) + " " + to_string(to->getId()) + to_string(idTo);
            funds[idFrom].AddHistory(history);
            to->funds[idTo].AddHistory(history);
        }
        else if (funds[idFrom].getFundBalance() < amount)
        {
            int trans = funds[idFrom].getFundBalance();
            funds[idFrom].RemoveAmount(trans);
            to->funds[idTo].AddAmount(trans);
            string history = "   T " + to_string(accountId) + to_string(idFrom) + " $" + to_string(trans) + " " + to_string(to->getId()) + to_string(idTo);
            funds[idFrom].AddHistory(history);
            to->funds[idTo].AddHistory(history);
        }
        else
        {
            funds[idFrom].RemoveAmount(amount);
            to->funds[idTo].AddAmount(amount);
            string history = "   T " + to_string(accountId) + to_string(idFrom) + " $" + to_string(amount) + " " + to_string(to->getId()) + to_string(idTo);
            funds[idFrom].AddHistory(history);
            to->funds[idTo].AddHistory(history);
        }

    }
    else if (funds[idFrom].getFundBalance() - amount < 0)
    {
        bool draft = funds[idFrom].hasOverDraft();
        int cover = funds[idFrom].getCoverageId();
        switch (draft)
        {
            case (true) :
                if (idTo == funds[idFrom].getCoverageId() && this->getId() != to->getId())
                {
                    if (this->getId() == to->getId() && funds[idFrom].getFundBalance() + funds[cover].getFundBalance() < amount)
                    {
                        string h("ERROR: COULD NOT TRANSFER $" + to_string(amount) + " FROM FUND " + to_string(idFrom) + " TO COVERAGE FUND " + to_string(idTo) + ", INSUFFICIENT FUNDS\n");
                        errors.push(h);
                        cerr << h;
                        break;
                    }
                    else
                    {
                        int cover = funds[idFrom].getCoverageId();
                        int trans = funds[idFrom].getFundBalance();
                        int transOther = -1 * (trans - amount);
                        to->funds[idTo].AddAmount(amount);
                        funds[cover].RemoveAmount(transOther);
                        funds[idFrom].RemoveAmount(trans);
                        string historyCover = "   T " + to_string(accountId) + to_string(cover) + " $" + to_string(transOther) + " " + to_string(to->getId()) + to_string(idTo);
                        string history = "   T " + to_string(accountId) + to_string(idFrom) + " $" + to_string(trans) + " " + to_string(to->getId()) + to_string(idTo);
                        funds[cover].AddHistory(historyCover);
                        funds[idFrom].AddHistory(history);
                        to->funds[idTo].AddHistory(history);
                        to->funds[idTo].AddHistory(historyCover);
                        break;
                    }
                }
                else
                {
                    if (funds[idFrom].getFundBalance() + funds[cover].getFundBalance() < amount)
                    {
                        string h("ERROR: COULD NOT TRANSFER $" + to_string(amount) + " FROM FUND " + to_string(idFrom) + " TO FUND " + to_string(idTo) + ", FUND AND COVERAGE FUND          HAVE INSUFFICIENT FUNDS\n");
                        errors.push(h);
                        cerr << h;
                        break;
                    }
                    int trans = funds[idFrom].getFundBalance();
                    int forCover = -1 * (trans - amount);
                    funds[cover].RemoveAmount(forCover);
                    funds[idFrom].RemoveAmount(trans);
                    to->funds[idTo].AddAmount(amount);
                    string history = "   T " + to_string(accountId) + to_string(idFrom) + " $" + to_string(trans) + " " + to_string(to->getId()) + to_string(idTo);
                    string historyCover = "   T " + to_string(accountId) + to_string(cover) + " $" + to_string(forCover) + " " + to_string(to->getId()) + to_string(idTo);
                    funds[idFrom].AddHistory(history);
                    funds[cover].AddHistory(historyCover);
                    to->funds[idTo].AddHistory(history);
                    to->funds[idTo].AddHistory(historyCover);
                    break;
                }
            case (false) :
                string history = "   T " + to_string(accountId) + to_string(idFrom) + " $" + to_string(amount) + " " + to_string(to->getId()) + to_string(idTo) + " (failed)";
                funds[idFrom].AddHistory(history);
                to->funds[idTo].AddHistory(history);
                string h("ERROR: COULD NOT TRANSFER $" + to_string(amount) + " FROM FUND " + to_string(idFrom) + " TO FUND " + to_string(idTo) + ", INSUFFICIENT FUNDS\n");
                errors.push(h);
                cerr << h;
                break;
        }
    }
    else
    {
        funds[idFrom].RemoveAmount(amount);
        to->funds[idTo].AddAmount(amount);
        string history = "   T " + to_string(accountId) + to_string(idFrom) + " $" + to_string(amount) + " " + to_string(to->getId()) + to_string(idTo);
        funds[idFrom].AddHistory(history);
        to->funds[idTo].AddHistory(history);
    }


}


void Account::History(const int&fundId) const
{
    if (fundId == 10)
    {
        cout << "Transaction History for " << accountHolder.getFirst() << " " << accountHolder.getLast() << " by fund." << endl;
        if (history.size() > 0)
        {
            GetHistory();
        }
        for (int i = 0; i < 10; i++)
        {
            if (funds[i].getHistorySize() > 0)
            {
                cout << funds[i] << funds[i].getHistory();
            }
        }
    }
    else
    {
        cout << "Transaction History for " << accountHolder.getFirst() << " " << accountHolder.getLast() << " " << funds[fundId].getFundName() << ": $" << funds[fundId].getFundBalance() << endl;
        cout << funds[fundId].getHistory();
    }
}

void Account::ErrorHistory()
{
    while (errors.size() > 0)
    {
        cerr << errors.front();
        errors.pop();
    }
}

ostream& operator << (ostream &os, Account &acct)
{
    cout << acct.accountHolder.getFirst() << " " << acct.accountHolder.getLast() << " ID:  " << acct.getId() << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "   " << acct.funds[i];
    }
    cout << endl;
    return os;
}
