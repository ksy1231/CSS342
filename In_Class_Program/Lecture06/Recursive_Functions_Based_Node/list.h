//
// Created by SooYeon Kim on 4/19/2018.
//

#ifndef RECURSIVE_FUNCTIONS_BASED_NODE_LIST_H
#define RECURSIVE_FUNCTIONS_BASED_NODE_LIST_H

#include "node.h"
using namespace std;

class List {
    friend ostream &operator<<(ostream &out, const List &myList);

private:
    Node<int>* headPtr;
    int itemCount;
public:
    List();
    virtual ~List();
    bool add(int data);
};

#endif //RECURSIVE_FUNCTIONS_BASED_NODE_LIST_H
