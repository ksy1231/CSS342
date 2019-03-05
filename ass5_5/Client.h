//
// Created by SooYeon Kim on 5/26/2018.
//

#ifndef ASS5_7_CLIENT_H
#define ASS5_7_CLIENT_H

#include<iostream>
#pragma once
using namespace std;
class Client
{

private:
    string first;
    string last;

public:

    Client(const string &firstName, const string &lastName);
    ~Client();

    string getFirst() const;
    string getLast() const;


    void setFirst(const string &newFirst);
    void setLast(const string &newLast);

};

#endif //ASS5_7_CLIENT_H
