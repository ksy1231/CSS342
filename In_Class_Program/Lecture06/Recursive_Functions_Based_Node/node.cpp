//
// Created by SooYeon Kim on 4/19/2018.
//

#include "node.h"

template<class ItemType>
ostream &operator<<(ostream &out, const Node<ItemType> &node) {
    out << "N<" << node.data << ">";
    return out;
}

template<class ItemType>
Node<ItemType>::Node(const ItemType &data, Node *next) :
    data{data}, next{next} {
}

template<class ItemType>
ItemType Node<ItemType>::getData() const {
    return data;
}

template<class ItemType>
Node<ItemType> *Node<ItemType>::getNext() {
    return next;
}

template<class ItemType>
void Node<ItemType>::setNext(Node *next) {
    this->next = next;
}