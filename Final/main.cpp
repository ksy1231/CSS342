#include <iostream>
#include <cassert>
#include <queue>

using namespace std;

class Square {
public:
    Square() {
        cout << "Constructor is called." << endl;
    }
    Square(int data) : data{data} {
        cout << "Copy constructor is called." << endl;
    }
    ~Square() {}

    int data;
};

void testQueue2() {
    queue<Square> myq;
    myq.push(Square(20));
    myq.push(Square(30));
    Square s4(40);
    myq.push(s4);
    assert(myq.size() == 3);
    assert(myq.front().data == 20);
    assert(myq.back().data == 40);
    myq.pop();
    myq.pop();
    assert(myq.size() == 1);
    myq.pop();
    assert(myq.empty());
    cout << "Done with queue" << endl;
}

void testQueue3() {
    queue<Square*> myq;
    myq.push(new Square(20)); // must delete it when popped
    myq.push(new Square(30));
    Square s4(40);
    myq.push(&s4);
    assert(myq.size() == 3);
    assert(myq.front()->data == 20);
    assert(myq.back()->data == 40);
    myq.pop();
    myq.pop();
    assert(myq.size() == 1);
    myq.pop();
    assert(myq.empty());
    cout << "Done with queue" << endl;
}

struct CompareSquarePtr {
    bool operator()(const Square *lhs, const Square *rhs) const {
        return lhs->data < rhs->data;
    }
};
/*
class CompareSquarePtr {
public:
    bool operator()(const Square *lhs, const Square *rhs) const {
        return lhs->data < rhs->data;
    }
};
*/
void testPQueue() {
    priority_queue<Square *,
            vector<Square *>, // storage container
            CompareSquarePtr> myq; // comparator
    myq.push(new Square(20));
    myq.push(new Square(30));
    myq.push(new Square(40));
    assert(myq.size() == 3);
    assert(myq.top()->data == 40);
    delete myq.top();
    myq.pop();
    delete myq.top();
    myq.pop();
    assert(myq.size() == 1);
    delete myq.top();
    myq.pop();
    assert(myq.empty());
    cout << "Done with queue" << endl;
}

class ATree {
public:
    ATree() {}
    bool Contains(int data) {
        return findNode(data, rootPtr) != nullptr;
    }
    bool CopyToTree(ATree &otherTree) {
        rootPtr = copyHelper(otherTree.rootPtr);
    }
private:
    struct Node {
        int data;
        Node* left;
        Node* right;
    };
    Node* rootPtr{nullptr};
    Node* findNode(int data, Node* startNode) {
        if (startNode == nullptr)
            return nullptr;
        else if (data == startNode->data)
            return startNode;
        else if (data < startNode->data)
            return findNode(data, startNode->left);
        else
            return findNode(data, startNode->right);
    }
    Node* copyHelper(const Node* other) {
        if(other == nullptr)
        {
            return nullptr; // 3
        }
        Node* newNode = new Node;
        if(other->data == 0)
        {
            newNode->data = 0; // 5
        }
        else
        {
            Node* newNodeData = new Node;
            newNodeData->data = other->data; // Copies data from other node.
            newNode->data = newNodeData->data;
        }
        newNode->left = copyHelper(other->left); // Recursive call to left node.
        newNode->right = copyHelper(other->right); // Recursive call to right node.
        return newNode; // Returns after child nodes have been linked to newNode.
    }
};

class Monster {
    public:
    void attack() {
        cout << "Grrr ";
    }
};

class Zombie : public Monster {
    public:
    void attack() {
        cout << "Brainz ";
    }
};

void testMonsters() {
    Monster m;
    Zombie z;

    m.attack();
    z.attack();

    Monster * mPtr = new Monster;
    Zombie * zPtr = new Zombie();

    mPtr->attack();
    zPtr->attack();

    delete mPtr;
    delete zPtr;
}

int main() {
    //testQueue2();
    //testQueue3();
    //testPQueue();
    testMonsters();
    std::cout << "Done!" << std::endl;
    return 0;
}