//
// Created by SooYeon Kim on 5/26/2018.
//

#ifndef ASS5_7_BSTREE_H
#define ASS5_7_BSTREE_H

#include "Account.h"
#pragma once
class BSTree
{

private:
    struct Node
    {
        Account *pAcct;
        Node *right = nullptr;
        Node *left = nullptr;
    };
    Node *root;
    int size;

    void recursiveDisplay(Node *print) const;
    void recursiveEmpty(Node *temp);
public:
    BSTree();
    ~BSTree();

    bool Insert(Account *toInsert);

    bool Retrieve(const int &acctId, Account*& objPtr) const;

    void Display() const;
    void Empty();
    bool isEmpty() const;
    int getSize() const;

};

#endif //ASS5_7_BSTREE_H
