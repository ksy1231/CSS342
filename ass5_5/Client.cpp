//
// Created by SooYeon Kim on 5/26/2018.
//

#include "stdafx.h"
#include "Client.h"


Client::Client(const string &firstName, const string &lastName) : first(firstName), last(lastName)
{
}


Client::~Client()
{
}

string Client::getFirst() const
{
    return first;
}

string Client::getLast() const
{
    return last;
}


void Client::setFirst(const string &newFirst)
{
    first = newFirst;
}

void Client::setLast(const string &newLast)
{
    last = newLast;
}
