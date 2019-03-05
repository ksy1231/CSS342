//
// Created by SooYeon Kim on 5/26/2018.
//

#ifndef ASS5_6_CUSTOMER_H
#define ASS5_6_CUSTOMER_H

#include "Person.h"

class Customer : public Person
{
private:
    int accountID;


public:
    Customer();
    Customer(int accountID);
    Customer(std::string firstName, std::string lastName);
    Customer(std::string firstName, std::string lastName, int accountID);
    Customer(const Customer &sourceObj);
    ~Customer();

    const int getAccountID() const;
    void setAccountID(const int accountID);

};


#endif //ASS5_6_CUSTOMER_H
