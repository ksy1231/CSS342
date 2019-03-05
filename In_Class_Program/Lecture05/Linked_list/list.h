//
// Created by SooYeon Kim on 4/19/2018.
//

#ifndef LINKED_LIST_LIST_H
#define LINKED_LIST_LIST_H

#include "node.h"
using namespace std;

class List {
    friend ostream &operator<<(ostream &out, const List &myList);

private:
    Node* headPtr;
    int itemCount;
public:
    List();
    virtual ~List();
    bool add(int data);
};

#endif //LINKED_LIST_LIST_H
