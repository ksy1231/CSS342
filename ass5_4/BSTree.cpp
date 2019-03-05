//
// Created by SooYeon Kim on 5/23/2018.
//

#include "stdafx.h"
#include "BSTree.h"

BSTree::BSTree()
{

}

BSTree::~BSTree()
{
    Empty();
}

bool BSTree::Insert(Account *incAcct)
{
    if (root == NULL)
    {
        Node *createdNode = new Node();
        createdNode->pAcct = new Account(*incAcct);
        createdNode->left = createdNode->right = NULL;
        root = createdNode;
        return true;
    }
    else
    {
        return insertHelper(this->root, incAcct);
    }
    return false;
}

bool BSTree::Retrieve(const int &targetId, Account *&incAcct) const
{
    return retrieveHelper(this->root, targetId, incAcct);
}

void BSTree::Display() const
{
    displayHelper(root);
    return;
}

void BSTree::Empty()
{
    emptyHelper(this->root);
    root = NULL;
    return;
}

bool BSTree::isEmpty() const
{
    return (root == NULL);
}

bool BSTree::insertHelper(Node *incNode, Account *incAcct)
{
    if (incAcct->getID() == incNode->pAcct->getID())
    {
        cerr << "ERROR: Account " << incNode->pAcct->getID() << " is already open. Transaction refused." << endl;
        return false;
    }
    else if (incAcct->getID() < incNode->pAcct->getID())
    {
        if (incNode->left == NULL)
        {
            Node *createdNode = new Node();
            createdNode->pAcct = new Account(*incAcct);
            incNode->left = createdNode;
            incNode->left->left = incNode->left->right = NULL;
            return true;
        }
        else
        {
            return insertHelper(incNode->left, incAcct);
        }
    }
    else if (incAcct->getID() > incNode->pAcct->getID())
    {
        if (incNode->right == NULL)
        {
            Node *createdNode = new Node();
            createdNode->pAcct = new Account(*incAcct);
            incNode->right = createdNode;
            incNode->right->left = incNode->right->right = NULL;
            return true;
        }
        else
        {
            return insertHelper(incNode->right, incAcct);
        }
    }
    else
    {
        return false;
    }
}

bool BSTree::retrieveHelper(const Node *incNode, const int &targetId, Account * &incAcct) const
{
    if (incNode == NULL)
    {
        return false;
    }
    else if (targetId == incNode->pAcct->getID())
    {
        incAcct = incNode->pAcct;
        return true;
    }
    else if (targetId < incNode->pAcct->getID())
    {
        retrieveHelper(incNode->left, targetId, incAcct);
    }
    else
    {
        retrieveHelper(incNode->right, targetId, incAcct);
    }
}

void BSTree::displayHelper(Node *incNode) const
{
    if (incNode == NULL)
    {
        return;
    }
    displayHelper(incNode->left);
    incNode->pAcct->DisplayAllFund();
    displayHelper(incNode->right);

}

// delete all is postorderTraverse
void BSTree::emptyHelper(Node *incNode)
{
    if (incNode == NULL)
    {
        return;
    }

    emptyHelper(incNode->left);
    emptyHelper(incNode->right);

    delete incNode->pAcct;
    incNode->pAcct = NULL;
    delete incNode;
    incNode = NULL;
    return;
}
