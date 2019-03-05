//
// Created by SooYeon Kim on 4/19/2018.
//

#ifndef RECURSIVE_FUNCTIONS_BASED_NODE_NODE_H
#define RECURSIVE_FUNCTIONS_BASED_NODE_NODE_H

#include <iostream>

using namespace std;

template <class ItemType>
class Node {
    template <class T> friend ostream &operator<<(ostream &out, const Node<T> &node);
    // template <class T> friend Node &operator>>(istream &in);

public:
    explicit Node(const ItemType &data = nullptr, Node* next = nullptr);
    ItemType getData() const;
    Node* getNext();
    void setNext(Node* next);
private:
    ItemType data;
    Node* next;
};

#include "node.cpp"

#endif //RECURSIVE_FUNCTIONS_BASED_NODE_NODE_H
