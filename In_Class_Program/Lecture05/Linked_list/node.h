//
// Created by SooYeon Kim on 4/19/2018.
//

#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H

#include <iostream>

using namespace std;

class Node {
    friend ostream &operator<<(ostream &out, const Node &node);

public:
    explicit Node(int data = 0, Node* next = nullptr);
    int getData() const;
    Node* getNext();
    void setNext(Node* next);

private:
    int data;
    Node* next;
};

#endif //LINKED_LIST_NODE_H
