//
// Created by SooYeon Kim on 5/23/2018.
//

#ifndef ASS5_3_BSTREE_H
#define ASS5_3_BSTREE_H

#include "Account.h"



class BSTree
{
    friend ostream& operator<<(ostream& stream, const BSTree& tree);
public:
    BSTree();
    ~BSTree();

    bool Insert(Account*);
    bool Retrieve(const Account &, Account * &) const;

    void Display();
    void Empty();
    bool IsEmpty();

    void Print();


private:
    struct Node
    {
        Account *pAccount;
        Node *left;
        Node *right;
    };
    Node *root = NULL;
    Account * RecurseSearch(Node *root, const Account &target) const;
    void RecurseInsert(Node *&root, Account *target);
    void Print(Node* root);
};

#endif //ASS5_3_BSTREE_H
