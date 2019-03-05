//
// Created by SooYeon Kim on 5/6/2018.
//

#include <cassert>
#include <climits>
#include <ctime>
#include "skiplist.h"

// print each level's data
ostream &operator<<(ostream &os, const SkipList &list) {
    for (int i = list.depth - 1; i >= 0; i--) {
        os << "Level: " << i << " -- ";
        for (SkipList::SNode * node = list.frontGuards[i]; node != nullptr;
             node = node->next) {
             os << node->data << ", ";
        }
        os << endl;
    }
    return os;
}

// set dynamic arrays based on the depth as INT_MIN and INT_MAX
// tie all the SNode objects together (both prev-next and up-down)
SkipList::SkipList(int depth) : depth{ depth } {
    srand(time(NULL));
    frontGuards = new SNode*[depth];
    rearGuards = new SNode*[depth];
    for (int i = 0; i < depth; i++) {
        frontGuards[i] = new SNode(INT_MIN);
        rearGuards[i] = new SNode(INT_MAX);
        frontGuards[i]->next = rearGuards[i];
        rearGuards[i]->prev = frontGuards[i];
    }
    for (int i = 0; i < depth - 1; i++) {
        frontGuards[i]->upLevel = frontGuards[i + 1];
        frontGuards[i + 1]->downLevel = frontGuards[i];
        rearGuards[i]->upLevel = rearGuards[i + 1];
        rearGuards[i + 1]->downLevel = rearGuards[i];
    }
}

// delete all data and arrays
SkipList::~SkipList() {
    for (int i = 0; i < depth; i++) {
        SNode* curr = frontGuards[i];
        while (curr != nullptr) {
            SNode* temp = curr->next;
            delete curr;
            curr = temp;
        }
    }
    delete[] frontGuards;
    delete[] rearGuards;
}

// add and build data and connect each other
bool SkipList::Add(int data) {
    SNode* nextNode = frontGuards[0]->next;
    frontGuards[0] = nextNode->prev;
    // keep moving nextNode to the right
    while (nextNode->next != nullptr && nextNode->data < data)
        nextNode = nextNode->next;
    // return false stating duplicates are not allowed
    if (nextNode->data == data)
        return false;
    // if not, create a new SNode
    else {
        auto* newNode = new SNode(data);
        addBefore(newNode, nextNode);
        // after inserting into level-0,
        // toss a coin to check if it should be inserted at higher level
        if (alsoHigher()) {
            for (int i = 1; i < depth; i++) {
                // create another node to be inserted at the higher level, newUpper
                auto *newUpper = new SNode(data);
                // connect newNode and newUpper (up-down)
                newNode->upLevel = newUpper;
                newUpper->downLevel = newNode;
                // starting from newNode that was inserted,
                // keep going back towards INT_MIN until you find a node
                // that has a valid upLevel link
                SNode *moveLeft = newNode;
                while (moveLeft->data != INT_MIN) {
                    moveLeft = moveLeft->prev;
                    // go up one level
                    if (moveLeft->upLevel != nullptr) {
                        moveLeft = moveLeft->upLevel;
                        break;
                    }
                }
                // go right towards INT_MAX
                SNode *moveRight = moveLeft;
                while (moveRight->data != INT_MAX) {
                    if (moveRight->downLevel->data < newNode->data)
                        break;
                    moveRight = moveRight->next;
                }
                // call addBefore to insert newUpper to come before the node
                // you just got to
                addBefore(newUpper, moveRight->next);
                // set newNode to be newUpper
                newNode = newUpper;
                // toss a coin to check if it should be inserted at higher level
                if (!alsoHigher())
                    break;
            }
        }
    }
    return true;
}

// remove data bottom to up
bool SkipList::Remove(int data) {
    for (int i = depth - 1; i > 0; i--) {
        SNode* remove = frontGuards[i]->next;
        frontGuards[i] = remove->prev;
        while (remove->next != nullptr && remove->data < data) {
            remove = remove->next;
        }
        if (remove->data == data) {
            remove->prev->next = remove->next;
            remove->next->prev = remove->prev;
            delete remove;
        }
        else if (remove->next == nullptr)
            return false;
    }
    return true;
}

// search whether the data exists or not
// do not want to search at level-0 that will be O(n)
bool SkipList::Contains(int data) {
    SNode* current = frontGuards[depth - 1];
    while (current != nullptr) {
        // keep moving right
        if (current->next->data < data)
            current = current->next;
        if (current->next->data == data)
            return true;
        else
            // set current to be the node down one level from current node
            current = current->downLevel;
    }
    return false;
}

// initialize data and pointers
SkipList::SNode::SNode(int data)
        : data{ data }, next{ nullptr }, prev{ nullptr }, upLevel{ nullptr },
          downLevel{ nullptr } {}

// connect previous pointer, newNode pointer, and nextNode pointer
void SkipList::addBefore(SkipList::SNode *newNode, SkipList::SNode *nextNode) {
    assert(newNode != nullptr && nextNode != nullptr &&
           newNode->data < nextNode->data);
    newNode->next = nextNode;
    newNode->prev = nextNode->prev;
    nextNode->prev->next = newNode;
    nextNode->prev = newNode;
    // after nodes have been linked
    assert(newNode->next == nextNode && nextNode->prev == newNode);
    assert(newNode->prev != nullptr && newNode->prev->data < newNode->data);
}

// check based on a coin toss
bool SkipList::alsoHigher() const {
    return (rand() % 2) == 1;
}
