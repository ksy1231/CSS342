//
// Created by SooYeon Kim on 4/19/2018.
//

#include "node.h"

template<class ItemType>
Node<ItemType>::Node() {

}

template<class ItemType>
Node<ItemType>::Node(const ItemType &anItem) {

}

template<class ItemType>
Node<ItemType>::Node(const ItemType &anItem, Node<ItemType> *nextNodePtr) {

}

template<class ItemType>
void Node<ItemType>::setItem(const ItemType &anItem) {

}

template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType> *nextNodePtr) {

}

template<class ItemType>
ItemType Node<ItemType>::getItem() const {
    return nullptr;
}

template<class ItemType>
Node<ItemType> *Node<ItemType>::getNext() const {
    return nullptr;
}
