//
// Created by SooYeon Kim on 4/19/2018.
//

#include "node.h"

ostream &operator<<(ostream &out, const Node &node) {
    out << "N<" << node.data << ">";
    return out;
}

Node::Node(int data, Node *next) :
    data{data}, next{next} {
}

int Node::getData() const {
    return data;
}

Node *Node::getNext() {
    return next;
}

void Node::setNext(Node *next) {
    this->next = next;
}
