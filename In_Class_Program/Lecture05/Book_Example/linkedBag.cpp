//
// Created by SooYeon Kim on 4/19/2018.
//

#include "linkedBag.h"

template<class ItemType>
Node<ItemType> *LinkedBag<ItemType>::getPointerTo(const ItemType &target) const {
    bool found = false;
    Node<ItemType>* curPtr = headPtr;
    while (!found && (curPtr != nullptr)) {
        if (target == curPtr->getItem())
            found = true;
        else
            curPtr = curPtr->getNext();
    } // end while

    return curPtr;
} // end getPointerTo

template<class ItemType>
Node<ItemType> *LinkedBag<ItemType>::getPointerTo(const ItemType &target, Node<ItemType> *curPtr) const {
    Node<ItemType>* result = nullptr;
    if (curPtr != nullptr) {
        if (target == curPtr->getItem())
            result = curPtr;
        else
            result = getPointerTo(target, curPtr->getNext());
    } // end if

    return result;
} // end getPointerTo

template<class ItemType>
LinkedBag<ItemType>::LinkedBag() : headPtr(nullptr), itemCount(0) {
} // end default constructor

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType> &aBag) {
    itemCount = aBag.itemCount;
    Node<ItemType>* origChainPtr = aBag.headPtr;
    if (origChainPtr == nullptr)
        headPtr = nullptr; // Original bag is empty; so is copy
    else {
        // Copy first node
        headPtr = new Node<ItemType>();
        headPtr->setItem(origChainPtr->getItem());

        // Copy remaining nodes
        Node<ItemType>* newChainPtr = headPtr; // Last-node pointer
            origChainPtr = origChainPtr->getNext(); // Advance pointer
        while (origChainPtr != nullptr) {
            // Get next item from original chain
            ItemType nextItem = origChainPtr->getItem();

            // Create a new node containing the next item
            Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);

            // Link new node to end of new chain
            newChainPtr->setNext(newNodePtr);

            // Advance pointers
            newChainPtr = newChainPtr->getNext();
            origChainPtr = origChainPtr->getNext();
        } // end while

        newChainPtr->setNext(nullptr); // Flag end of new chain
    } // end if
} // end copy constructor

template<class ItemType>
LinkedBag<ItemType>::~LinkedBag() {
    clear();
} // end destructor

template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const {
    return itemCount;
} // end getCurrentSize

template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const {
    return itemCount == 0;
} // end isEmpty

template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType &newEntry) {
    // Add to beginning of chain: new node references rest of chain;
    // (headPtr is nullPtr if chain is empty)
    Node<ItemType>* newNodePtr = new Node<ItemType>();
    newNodePtr->setItem(newEntry);
    newNodePtr->setNext(headPtr); // New node points to chain
    headPtr = newNodePtr; // New node is now first node
    itemCount++;

    return ture;
} // end add

template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType &anEntry) {
    Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
    bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);
    if (canRemoveItem) {
        // Copy data from first node to located node
        entryNodePtr->setItem(headPtr->getItem());

        // Disconnect first node
        Node<ItemType>* nodeToDeletePtr = headPtr;
        headPtr = headPtr->getNext();

        // Return node to the system
        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;
        nodeToDeletePtr = nullptr;

        itemCount--;
    } // end if

    return canRemoveItem;
} // end remove

template<class ItemType>
void LinkedBag<ItemType>::clear() {
    Node<ItemType>* nodeToDeletePtr = headPtr;
    while (headPtr != nullptr) {
        headPtr = headPtr->getNext();

        // Return node to the system
        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;
        nodeToDeletePtr = headPtr;
    } // end while
    // headPtr is nullptr; nodeToDeletePtr is nullptr

    itemCount = 0;
} // end clear

template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType &anEntry) const {
    return (getPointerTo(anEntry) != nullptr);
} // end contains

template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType &anEntry) const {
    return frequency;
} // end getFrequencyOf

template<class ItemType>
vector <ItemType> LinkedBag<ItemType>::toVector() const {
    return nullptr;
}

