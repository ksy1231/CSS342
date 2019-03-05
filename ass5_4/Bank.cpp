//
// Created by SooYeon Kim on 5/23/2018.
//

#include "stdafx.h"
#include "Bank.h"

Bank::Bank()
{
}

Bank::~Bank()
{
}

void Bank::ReadTxtFile(string file)
{
    ifstream inFile;
    inFile.open(file);

    if (inFile.is_open())
    {
        while (!inFile.eof())
        {
            Transaction Request;
            inFile >> Request;
            requestList.push(Request);
        }
        inFile.close();
        return;
    }
    else
    {
        cerr << "Error occurred in read in text file!!!" << endl;
        return;
    }
}

void Bank::ProceedQue()
{
    while (requestList.size() != 0)
    {
        string curTransactionType = requestList.front().getTransactionType();
        if (curTransactionType == "O")
        {
            openAccount(requestList.front());
        }
        if (curTransactionType == "D")
        {
            deposit(requestList.front());
        }
        if (curTransactionType == "W")
        {
            withdraw(requestList.front());
        }
        if (curTransactionType == "T")
        {
            transfer(requestList.front());
        }
        if (curTransactionType == "H")
        {
            history(requestList.front());
        }
        requestList.pop();
    }

    return;
}

void Bank::DisplayAllAccount() const
{
    cout << endl;
    cout << "Processing Done. Final Balances " << endl;
    this->acctInfoTree.Display();
    return;
}

bool Bank::openAccount(Transaction &incTransaction)
{
    Account *curAcct = NULL;
    int curMainAcctID = incTransaction.getMainAcctID();
    bool acctAvailable = acctInfoTree.Retrieve(curMainAcctID, curAcct);

    if (acctAvailable)
    {
        cerr << "ERROR: Account " << curMainAcctID << " is already opened. Opening account refused." << endl;
        return false;
    }
    else
    {
        if (incTransaction.getMainAcctID() >= 1000 && incTransaction.getMainAcctID() <= 9999)
        {
            Account createdAccount(incTransaction.getLastName(), incTransaction.getFirstName(), incTransaction.getMainAcctID());
            this->acctInfoTree.Insert(&createdAccount);
            return true;
        }
        else
        {
            cerr << "ERROR: Account ID have to be 4 digit. Opening account refused." << endl;
            return false;
        }
    }
}

bool Bank::deposit(Transaction &incTransaction)
{
    Account *curAcct = NULL;
    int curMainAcctID = incTransaction.getMainAcctID();
    int curMainFundTypeID = incTransaction.getMainFundTypeID();
    bool acctAvailable = acctInfoTree.Retrieve(curMainAcctID, curAcct);

    if (acctAvailable && incTransaction.getAmount() >= 0 && incTransaction.getMainFundTypeID() >= 0)
    {
        curAcct->getFund(incTransaction.getMainFundTypeID())->Deposit(incTransaction.getAmount());
        curAcct->getFund(incTransaction.getMainFundTypeID())->AddHistory(incTransaction);
        return true;
    }
    else
    {
        if (incTransaction.getAmount() < 0)
        {
            incTransaction.setValidTrans(false);
            curAcct->getFund(curMainFundTypeID)->AddHistory(incTransaction);
            cerr << "ERROR: $" << incTransaction.getAmount() << " is not possible amount to make transaction. Deposit refused. " << endl;
            return false;
        }
        else if (incTransaction.getMainFundTypeID() < 0)
        {
            cerr << "ERROR: Fund ID have not been found. Deposit refused." << endl;
            return false;
        }
        else
        {
            cerr << "ERROR: Account " << curMainAcctID << " was not found. Deposit refused. " << endl;
            return false;
        }
    }
}

bool Bank::withdraw(Transaction &incTransaction)
{
    Account *curAcct = NULL;
    int curMainAcctID = incTransaction.getMainAcctID();
    int curMainFundTypeID = incTransaction.getMainFundTypeID();
    bool acctAvailable = acctInfoTree.Retrieve(curMainAcctID, curAcct);

    if (acctAvailable && incTransaction.getAmount() >= 0 && incTransaction.getMainFundTypeID() >= 0)
    {
        if (curAcct->getFund(curMainFundTypeID)->getBalance() < incTransaction.getAmount())
        {
            if (curMainFundTypeID == 0 || curMainFundTypeID == 2)
            {
                int sumTwoBalance = curAcct->getFund(curMainFundTypeID)->getBalance() + curAcct->getFund(curMainFundTypeID + 1)->getBalance();
                int remainAmount = incTransaction.getAmount() - curAcct->getFund(curMainFundTypeID)->getBalance();

                if (sumTwoBalance < incTransaction.getAmount())
                {
                    incTransaction.setValidTrans(false);
                    curAcct->getFund(curMainFundTypeID)->AddHistory(incTransaction);
                    cerr << "ERROR: Not enough fund to Withdraw " << incTransaction.getAmount() << " from " << curAcct->getFund(curMainFundTypeID)->getFundName() << "." << endl;
                    return false;
                }
                else
                {
                    curAcct->getFund(curMainFundTypeID)->setBalance(0);
                    curAcct->getFund(curMainFundTypeID + 1)->Withdraw(remainAmount);
                    incTransaction.setAmount(incTransaction.getAmount() - remainAmount);
                    curAcct->getFund(curMainFundTypeID)->AddHistory(incTransaction);
                    incTransaction.setAmount(remainAmount);
                    incTransaction.setMainFundTypeID(incTransaction.getMainFundTypeID() + 1);
                    curAcct->getFund(curMainFundTypeID + 1)->AddHistory(incTransaction);
                    return true;
                }
            }
            else if (curMainFundTypeID == 1 || curMainFundTypeID == 3)
            {
                int sumTwoBalance = curAcct->getFund(curMainFundTypeID)->getBalance() + curAcct->getFund(curMainFundTypeID - 1)->getBalance();
                int remainAmount = incTransaction.getAmount() - curAcct->getFund(curMainFundTypeID)->getBalance();

                if (sumTwoBalance < incTransaction.getAmount())
                {
                    incTransaction.setValidTrans(false);
                    curAcct->getFund(curMainFundTypeID)->AddHistory(incTransaction);
                    cerr << "ERROR: Not enough fund to Withdraw " << incTransaction.getAmount() << " from " << curAcct->getFund(curMainFundTypeID)->getFundName() << "." << endl;
                    return false;
                }
                else
                {
                    curAcct->getFund(curMainFundTypeID)->setBalance(0);
                    curAcct->getFund(curMainFundTypeID - 1)->Withdraw(remainAmount);
                    incTransaction.setAmount(incTransaction.getAmount() - remainAmount);
                    curAcct->getFund(curMainFundTypeID)->AddHistory(incTransaction);
                    incTransaction.setAmount(remainAmount);
                    incTransaction.setMainFundTypeID(incTransaction.getMainFundTypeID() - 1);
                    curAcct->getFund(curMainFundTypeID - 1)->AddHistory(incTransaction);
                    return true;
                }
            }
            else
            {
                incTransaction.setValidTrans(false);
                curAcct->getFund(curMainFundTypeID)->AddHistory(incTransaction);
                cerr << "ERROR: Not enough fund to Withdraw " << incTransaction.getAmount() << " from " << curAcct->getFund(curMainFundTypeID)->getFundName() << "." << endl;
                return false;
            }
        }
        else
        {
            curAcct->getFund(curMainFundTypeID)->Withdraw(incTransaction.getAmount());
            curAcct->getFund(curMainFundTypeID)->AddHistory(incTransaction);
            return true;
        }
    }
    else
    {
        if (incTransaction.getAmount() < 0)
        {
            incTransaction.setValidTrans(false);
            curAcct->getFund(curMainFundTypeID)->AddHistory(incTransaction);
            cerr << "ERROR: $" << incTransaction.getAmount() << " is not possible amount to make transaction. Witdraw refused. " << endl;
            return false;
        }
        else if (incTransaction.getMainFundTypeID() < 0)
        {
            cerr << "ERROR: Fund ID have not been found. Withdraw refused." << endl;
            return false;
        }
        else
        {
            cerr << "ERROR: Account " << curMainAcctID << " was not found. Withdraw refused. " << endl;
            return false;
        }
    }
}

bool Bank::transfer(Transaction &incTransaction)
{
    Account *curAcct = NULL;
    Account *curSecondAcct = NULL;
    int curMainAcctID = incTransaction.getMainAcctID();
    int curMainFundTypeID = incTransaction.getMainFundTypeID();
    int curSecondAcctID = incTransaction.getSecondAcctID();
    int curSecondFundTypeID = incTransaction.getSecondFundTypeID();
    bool acctAvailable = acctInfoTree.Retrieve(curMainAcctID, curAcct);
    bool secondAcctAvailable = acctInfoTree.Retrieve(curSecondAcctID, curSecondAcct);
    int remainAmount = incTransaction.getAmount() - curAcct->getFund(curMainFundTypeID)->getBalance();

    if (acctAvailable && secondAcctAvailable && (incTransaction.getAmount() > 0) && (incTransaction.getMainFundTypeID() >= 0))
    {
        if (curAcct->getFund(curMainFundTypeID)->getBalance() < incTransaction.getAmount())
        {
            if (curMainFundTypeID == 0 || curMainFundTypeID == 2)
            {
                if (remainAmount < (curAcct->getFund(curMainFundTypeID + 1)->getBalance()))
                {
                    curAcct->getFund(curMainFundTypeID)->Withdraw(incTransaction.getAmount() - remainAmount);
                    curAcct->getFund(curMainFundTypeID + 1)->Withdraw(remainAmount);
                    curSecondAcct->getFund(curSecondFundTypeID)->Deposit(incTransaction.getAmount());
                    incTransaction.setAmount(incTransaction.getAmount() - remainAmount);
                    curAcct->getFund(curMainFundTypeID)->AddHistory(incTransaction);
                    curSecondAcct->getFund(curSecondFundTypeID)->AddHistory(incTransaction);

                    incTransaction.setAmount(remainAmount);
                    incTransaction.setMainFundTypeID(incTransaction.getMainFundTypeID() + 1);
                    curAcct->getFund(curMainFundTypeID + 1)->AddHistory(incTransaction);

                    curSecondAcct->getFund(curSecondFundTypeID)->AddHistory(incTransaction);

                    return true;
                }
            }
            else if (curMainFundTypeID == 1 || curMainFundTypeID == 3)
            {
                if ((remainAmount < (curAcct->getFund(curMainFundTypeID - 1)->getBalance())))
                {
                    curAcct->getFund(curMainFundTypeID)->Withdraw(incTransaction.getAmount() - remainAmount);
                    curAcct->getFund(curMainFundTypeID - 1)->Withdraw(remainAmount);
                    curSecondAcct->getFund(curSecondFundTypeID)->Deposit(incTransaction.getAmount());
                    incTransaction.setAmount(incTransaction.getAmount() - remainAmount);
                    curAcct->getFund(curMainFundTypeID)->AddHistory(incTransaction);
                    curSecondAcct->getFund(curSecondFundTypeID)->AddHistory(incTransaction);

                    incTransaction.setAmount(remainAmount);
                    incTransaction.setMainFundTypeID(incTransaction.getMainFundTypeID() - 1);
                    curAcct->getFund(curMainFundTypeID - 1)->AddHistory(incTransaction);

                    curSecondAcct->getFund(curSecondFundTypeID)->AddHistory(incTransaction);

                    return true;
                }
            }

            incTransaction.setValidTrans(false);
            curAcct->getFund(curMainFundTypeID)->AddHistory(incTransaction);
            if (curMainAcctID != curSecondAcctID)
            {
                curSecondAcct->getFund(curSecondFundTypeID)->AddHistory(incTransaction);
            }
            cerr << "ERROR: Account ID " << curMainAcctID << " " << curAcct->getFund(curMainFundTypeID)->getFundName()
                 << " have insufficient balance to make Transfer to Account ID " << curSecondAcctID << " "
                 << curAcct->getFund(curSecondFundTypeID)->getFundName() << ". Transfer refused." << endl;
            return false;
        }
        else
        {
            curAcct->getFund(curMainFundTypeID)->Withdraw(incTransaction.getAmount());
            curSecondAcct->getFund(curSecondFundTypeID)->Deposit(incTransaction.getAmount());
            curAcct->getFund(curMainFundTypeID)->AddHistory(incTransaction);

            if (curMainAcctID != curSecondAcctID)
            {
                curSecondAcct->getFund(curSecondFundTypeID)->AddHistory(incTransaction);
            }
            else if (curMainFundTypeID != curSecondFundTypeID)
            {
                curAcct->getFund(curSecondFundTypeID)->AddHistory(incTransaction);
            }
            return true;
        }
    }
    else
    {
        if (incTransaction.getAmount() < 0)
        {
            incTransaction.setValidTrans(false);
            curAcct->getFund(curMainFundTypeID)->AddHistory(incTransaction);
            if (curMainAcctID != curSecondAcctID)
            {
                curSecondAcct->getFund(curSecondFundTypeID)->AddHistory(incTransaction);
            }
            cerr << "ERROR: $" << incTransaction.getAmount() << " is not possible amount to make transaction. Transfer refused. " << endl;
            return false;
        }
        else if (incTransaction.getMainFundTypeID() < 0 || incTransaction.getSecondFundTypeID() < 0)
        {
            cerr << "ERROR: Fund ID have not been found. Transfer refused." << endl;
            return false;
        }

        else if (!acctAvailable)
        {
            cerr << "ERROR: Account " << curMainAcctID << " was not found. Transfer refused. " << endl;
            return false;
        }
        else
        {
            cerr << "ERROR: Account " << curSecondAcctID << " was not found. Transfer refused. " << endl;
            return false;
        }
    }
}

bool Bank::history(Transaction &incTransaction)
{
    Account *curAcct = NULL;
    int curMainAcctID = incTransaction.getMainAcctID();
    int curMainFundTypeID = incTransaction.getMainFundTypeID();
    bool acctAvailable = acctInfoTree.Retrieve(curMainAcctID, curAcct);

    if (acctAvailable)
    {
        if (curMainFundTypeID < 0)
        {
            cout << "Transaction History for " << curAcct->getFirstName() << " " << curAcct->getLastName() << " by fund." << endl;
            for (int j = 0; j < TOTAL_TYPES_OF_FUND; j++)
            {
                if (!(curAcct->getFund(j)->isHistoryEmpty()))
                {
                    cout << curAcct->getFund(j)->getFundName() << ": $" << curAcct->getFundBalance(j) << endl;
                    curAcct->getFund(j)->DisplayHistory();
                }
            }
            return true;
        }
        else
        {
            cout << "Transaction History for " << curAcct->getFirstName() << " " << curAcct->getLastName()
                 << " " << curAcct->getFund(curMainFundTypeID)->getFundName() << ": $" << curAcct->getFundBalance(curMainFundTypeID) << endl;
            curAcct->getFund(curMainFundTypeID)->DisplayHistory();
            return true;
        }
    }
    else
    {
        cerr << "ERROR: Account " << curMainAcctID << " was not found. Process history refused. " << endl;
        return false;
    }
}
