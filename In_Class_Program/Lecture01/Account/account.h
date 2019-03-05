//
// Created by SooYeon Kim on 2018-03-29.
//

#ifndef ACCOUNT_ACCOUNT_H
#define ACCOUNT_ACCOUNT_H

#include <iostream>

class Account {
    friend ostream &operator<<(ostream &out, const Account &acc);

public:
    // constructor
    Account();

    // destructor
    ~Account();

    // get the current balance
    int GetBalance() const;

    // deposit money into account
    // return true if successful, false otherwise
    // deposit is always successful
    bool Deposit (int amount);

    // withdraw money from account
    // return true if successful, false if not enough money
    bool Withdraw(int amount);

private:
    // current balance
    int balance;
};

#endif //ACCOUNT_ACCOUNT_H
