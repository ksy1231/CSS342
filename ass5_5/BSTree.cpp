//
// Created by SooYeon Kim on 5/26/2018.
//

#include "stdafx.h"
#include "BSTree.h"


BSTree::BSTree() : root(nullptr), size(0)
{
}


BSTree::~BSTree()
{
    Empty();
}

bool BSTree::Insert(Account *toInsert)
{
    if (toInsert->getId() < 1000 || toInsert->getId() > 9999)
    {
        return false;
    }
    else if (root == nullptr)
    {
        root = new Node;
        root->pAcct = toInsert;
        return true;
    }
    Node *current = root;
    int id = toInsert->getId();
    bool done = false;
    while (!done)
    {
        if (id < current->pAcct->getId() && current->left != nullptr)
        {
            current = current->left;
        }
        else if (id > current->pAcct->getId() && current->right != nullptr)
        {
            current = current->right;
        }
        else if (id == current->pAcct->getId())
        {
            return false;
        }
        else if (id < current->pAcct->getId())
        {
            done = true;
            current->left = new Node;
            current->left->pAcct = toInsert;
            size++;
            return done;
        }
        else
        {
            done = true;
            current->right = new Node;
            current->right->pAcct = toInsert;
            size++;
            return done;
        }
    }
    return false;
}

bool BSTree::Retrieve(const int &acctId, Account*& objPtr) const
{
    bool done = false;
    Node *temp = root;
    while (!done)
    {
        if (temp != nullptr && acctId == temp->pAcct->getId())
        {
            done = true;
            objPtr = temp->pAcct;
            return done;
        }
        else if (temp != nullptr && acctId < temp->pAcct->getId())
        {
            temp = temp->left;
        }
        else if (temp != nullptr && acctId > temp->pAcct->getId())
        {
            temp = temp->right;
        }
        else
        {
            done = true;
        }
    }
    return false;
}

void BSTree::Display() const
{
    if (root == nullptr)
    {
        cerr << "ERROR: THERE ARE NO ACCOUNTS" << endl;
    }
    else
    {
        recursiveDisplay(root);
    }
}

void BSTree::Empty()
{
    if (root == nullptr)
    {
        return;
    }
    Node *temp = root;
    recursiveEmpty(temp);
    root = nullptr;
}

bool BSTree::isEmpty() const
{
    return size == 0;
}

void BSTree::recursiveDisplay(Node *print) const
{
    if (print->left != nullptr && print->right != nullptr)
    {
        recursiveDisplay(print->left);
        cout << *print->pAcct << endl;
        recursiveDisplay(print->right);
    }
    else if (print->left != nullptr)
    {
        recursiveDisplay(print->left);
        cout << *print->pAcct << endl;
    }
    else if (print->right != nullptr)
    {
        cout << *print->pAcct << endl;
        recursiveDisplay(print->right);
    }
    else
    {
        cout << *print->pAcct << endl;
    }
}

void BSTree::recursiveEmpty(Node *temp)
{
    if (temp->left != nullptr && temp->right != nullptr)
    {
        recursiveEmpty(temp->left);
        recursiveEmpty(temp->right);
        delete temp->pAcct;
        temp->pAcct = nullptr;

    }
    else if (temp->left != nullptr)
    {
        recursiveEmpty(temp->left);
        delete temp->pAcct;
        temp->pAcct = nullptr;
        size--;
        delete temp;
    }
    else if (temp->right != nullptr)
    {
        recursiveEmpty(temp->right);
        delete temp->pAcct;
        temp->pAcct = nullptr;
        temp->right = nullptr;
        size--;
        delete temp;
    }
    else
    {
        delete temp->pAcct;
        temp->pAcct = nullptr;
        temp->left = nullptr;
        temp->right = nullptr;
        size--;
        delete temp;
    }

}
int BSTree::getSize() const
{
    return size;
}
