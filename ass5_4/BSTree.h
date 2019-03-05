//
// Created by SooYeon Kim on 5/23/2018.
//

#ifndef ASS5_4_BSTREE_H
#define ASS5_4_BSTREE_H

#include "Account.h"
#include <iostream>

using namespace std;

class BSTree
{
public:
    BSTree();
    ~BSTree();

    bool Insert(Account *);
    bool Retrieve(const int &, Account *&) const;

    void Display() const;
    void Empty();
    bool isEmpty() const;

private:
    struct Node
    {
        Account *pAcct = NULL;
        Node *right = NULL;
        Node *left = NULL;
    };
    Node *root = NULL;

    bool insertHelper(Node *incNode, Account *incAcct);
    bool retrieveHelper(const Node *incNode, const int &targetId, Account *&incAcct) const;
    void displayHelper(Node *incNode) const;
    void emptyHelper(Node *incNode);

};

#endif //ASS5_4_BSTREE_H
