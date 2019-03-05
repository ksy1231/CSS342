//
// Created by SooYeon Kim on 5/26/2018.
//

#ifndef ASS5_5_TRANSACTIONFACTORY_H
#define ASS5_5_TRANSACTIONFACTORY_H

#include "Transaction.h"

class TransactionFactory
{
public:
    Transaction* createTransaction(istream &sin);
};

#endif //ASS5_5_TRANSACTIONFACTORY_H
