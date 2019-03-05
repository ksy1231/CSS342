//
// Created by SooYeon Kim on 5/26/2018.
//

#include "stdafx.h"
#include "Bank.h"



Bank::Bank() : bankAccounts(), theQueue()
{
}


Bank::~Bank()
{
}

void Bank::buildQueue(string FileName)
{
    fstream inFile(FileName);
    while (inFile.peek() != EOF)
    {
        if (inFile.peek() == '\n')
        {
            inFile.ignore(1);
        }
        Transaction t;
        inFile >> t;
        theQueue.push(t);
    }
}

void Bank::useQueue()
{
    while (theQueue.size() > 0)
    {
        if (theQueue.front().getAction() == 'T')
        {
            if (theQueue.front().getAcctId() < 1000 || theQueue.front().getAcctId() > 9999 || theQueue.front().getOtherAccountId() < 1000 || theQueue.front().getOtherAccountId() > 9999)
            {
                if ((theQueue.front().getAcctId() < 1000 || theQueue.front().getAcctId() > 9999) && (theQueue.front().getOtherAccountId() < 1000 || theQueue.front().getOtherAccountId() > 9999))
                {
                    string h("ERROR: ACCOUNT ID " + to_string(theQueue.front().getAcctId()) + " AND " + to_string(theQueue.front().getOtherAccountId()) + " ARE BOTH INVALID, COULD NOT TRANSFER $" + to_string(theQueue.front().getAmount()));
                    history.push(h);
                    cerr << h << endl;
                }
                else if (theQueue.front().getAcctId() < 1000 || theQueue.front().getAcctId() > 9999)
                {
                    string h("ERROR: ACCOUNT ID " + to_string(theQueue.front().getAcctId()) + " IS INVALID, COULD NOT TRANSFER $" + to_string(theQueue.front().getAmount()));
                    history.push(h);
                    cerr << h << endl;
                }
                else if (theQueue.front().getFundId() == theQueue.front().getOtherFundId())
                {
                    string h("ERROR: CANNOT TRANSFER FROM A FUND TO ITSELF");
                    history.push(h);
                    cerr << h << endl;
                }
                else
                {
                    string h("ERROR: ACCOUNT ID " + to_string(theQueue.front().getOtherAccountId()) + " IS INVALID, COULD NOT TRANSFER $" + to_string(theQueue.front().getAmount()));
                    history.push(h);
                    cerr << h << endl;
                }
                theQueue.pop();
            }
            else
            {
                if (theQueue.front().getAcctId() != theQueue.front().getOtherAccountId())
                {
                    Account *test;
                    Account *test2;
                    bool work = bankAccounts.Retrieve(theQueue.front().getAcctId(), test);
                    bool work2 = bankAccounts.Retrieve(theQueue.front().getOtherAccountId(), test2);
                    if (work && work2)
                    {
                        test->Transfer(theQueue.front().getAmount(), theQueue.front().getFundId(), test2, theQueue.front().getOtherFundId());
                    }
                    else if (!work && !work2)
                    {
                        string h("ERROR: ACCOUNT ID " + to_string(theQueue.front().getAcctId()) + " AND " + to_string(theQueue.front().getOtherAccountId()) + " DO NOT EXIST... COULD NOT TRANSFER");
                        history.push(h);
                        cerr << h << endl;
                    }
                    else if (!work)
                    {
                        string h("ERROR: ACCOUNT ID " + to_string(theQueue.front().getAcctId()) + " DOES NOT EXIST AND COULD NOT BE TRANSFERRED FROM");
                        history.push(h);
                        cerr << h << endl;
                    }
                    else
                    {
                        string h("ERROR: ACCOUNT ID " + to_string(theQueue.front().getOtherAccountId()) + " DOES NOT EXIST AND COULD NOT BE TRANSFERRED TO");
                        history.push(h);
                        cerr << h << endl;
                    }
                    test = nullptr;
                    test2 = nullptr;
                    theQueue.pop();
                }
                else
                {
                    Account *use;
                    bankAccounts.Retrieve(theQueue.front().getAcctId(), use);
                    use->determineAction(theQueue.front());
                    theQueue.pop();

                }
            }
        }
        else if (theQueue.front().getAction() == 'O')
        {
            if (theQueue.front().getAcctId() < 1000 || theQueue.front().getAcctId() > 9999)
            {
                string h = "ERROR: ACCOUNT ID " + to_string(theQueue.front().getAcctId()) + " IS INVALID, COULD NOT OPEN ACCOUNT FOR " + theQueue.front().getFirst() + " " + theQueue.front().getLast();
                history.push(h);
                cerr << h << endl;
            }
            else
            {
                Account *make = new Account(theQueue.front().getFirst(), theQueue.front().getLast(), theQueue.front().getAcctId());
                bool work = bankAccounts.Insert(make);
                if (!work)
                {
                    string h = "ERROR: ACCOUNT ID " + to_string(make->getId()) + " ALREADY EXISTS, COULD NOT OPEN ACCOUNT FOR " + theQueue.front().getFirst() + " " + theQueue.front().getLast();
                    history.push(h);
                    cerr << h << endl;
                }
            }
            theQueue.pop();
        }
        else
        {
            if (theQueue.front().getAcctId() < 1000 || theQueue.front().getAcctId() > 9999)
            {
                string h = "ERROR: ACCOUNT ID " + to_string(theQueue.front().getAcctId());
                if (theQueue.front().getAction() == 'D')
                {
                    h += " IS INVALID, COULD NOT DEPOSIT $";
                    h += to_string(theQueue.front().getAmount());
                }
                else if (theQueue.front().getAction() == 'W')
                {
                    h += " IS INVALID, COULD NOT WITHDRAW $";
                    h += to_string(theQueue.front().getAmount());
                }
                else if (theQueue.front().getAction() == 'T')
                {
                    h += " IS INVALID, COULD NOT WITHDRAW $";
                    h += to_string(theQueue.front().getAmount());
                }
                else if (theQueue.front().getAction() == 'H')
                {
                    h += " IS INVALID, COULD NOT DISPLAY HISTORY";
                }
                cerr << h << endl;
                history.push(h);
                theQueue.pop();
            }
            else
            {
                Account *use;
                bool work = bankAccounts.Retrieve(theQueue.front().getAcctId(), use);
                if (!work)
                {
                    string h = "ERROR: ACCOUNT ID " + to_string(theQueue.front().getAcctId());
                    if (theQueue.front().getAction() == 'D')
                    {
                        h += " DOES NOT EXIST, COULD NOT DEPOSIT $";
                        h += to_string(theQueue.front().getAmount());
                    }
                    else if (theQueue.front().getAction() == 'W')
                    {
                        h += " DOES NOT EXIST, COULD NOT WITHDRAW $";
                        h += to_string(theQueue.front().getAmount());
                    }
                    else if (theQueue.front().getAction() == 'T')
                    {
                        h += " DOES NOT EXIST, COULD NOT TANSFER $";
                        h += to_string(theQueue.front().getAmount());
                    }
                    else if (theQueue.front().getAction() == 'H')
                    {
                        h += " DOES NOT EXIST, COULD NOT DISPLAY HISTORY";
                    }
                    cerr << h << endl;
                    history.push(h);
                    theQueue.pop();
                }
                else
                {
                    use->determineAction(theQueue.front());
                    theQueue.pop();
                }
            }
        }
    }
    cout << "\nProcessing Done. Final Balances" << endl;
    bankAccounts.Display();
}
