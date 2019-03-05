//
// Created by SooYeon Kim on 2018-03-29.
//

#include "account.h"
#include <iostream>
using namespace std;

ostream &operator<<(ostream &out, const Account &acc) {
    out << "A<" << acc.balance << ">";
    return out;
}

Account::Account() {
    balance = 0;
}

Account::~Account() {
    // nothing to do
}

int Account::GetBalance() const {
    return balance;
}

bool Account::Deposit(int amount) {
    balance += amount;
    return true;
}

bool Account::Withdraw(int amount) {
    if(balance >= amount) {
        balance -= amount;
        return true;
    } else {
        return false;
    }
}