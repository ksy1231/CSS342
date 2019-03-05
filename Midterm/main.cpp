#include <iostream>
#include <cassert>

using namespace std;

// #3
// Call by Value, Reference, const Reference
struct Rectangle {
    int length;
    int width;
};

//int Area(Rectangle rect) // value rect is copied
int Area(Rectangle &rect) // reference, can change rect
//int Area(const Rectangle &rect) // const reference, cannot change rect
{
    int temp;
    temp = rect.length;
    rect.length = 35;
    return (temp * rect.width);
}

void TestRectangle() {
    cout << "#3" << endl;
    int result;
    Rectangle r = {3, 3};
    result = Area(r);
    cout << "length = " << r.length << endl;
    cout << "width = " << r.width << endl;
    cout << "Area = " << result << endl;
}

// by value
void swap(string a, string b) {
    string tmp = a;
    a= b;
    b = tmp;
}

// by reference
void swap2(string a, string b) {
    string tmp = a;
    a = b;
    b = tmp;
}

// by const reference
void swap3(string a, string b) {
    string tmp = a;
    a = b;
    b = tmp;
}

// #6
bool findMaxMin(int anArray[], int arrayLength, int &maxValue, int &minValue) {
    if (anArray == nullptr)
        return false;
    else {
        for (int i {0}; i < arrayLength; i++) {
            if (anArray[i] < minValue)
                minValue = anArray[i];
            if (anArray[i] > maxValue)
                maxValue = anArray[i];
        }
        return true;
    }
}

// #7
int sumUpTo(int n) {
    cout << "#7" << endl;
    cout << "n: " << n << endl;
    int sum = 0;
    if (n == 1) {
        cout << "base: " << n << endl;
        sum = 1;
    } else {
        sum = n + sumUpTo(n - 1);
    }
    cout << "sum: " << sum << endl;
    return sum;
}

// #8
int gcdDijkstra(int m, int n) {
    if (m == n)
        return m;
    else if (m > n)
        return gcdDijkstra(m - n, n);
    else
        return gcdDijkstra(m, n - m);
}

class Square {
public:
    Square(int size = 0) : size{size} {};
    int getSize() const {return size;}
    Square operator+(const Square &sqr) const;
    Square& operator+=(const Square &sqr);
private:
    int size;
};

Square Square::operator+(const Square &sqr) const {
    Square sum;
    sum.size = size + sqr.size;
    return sum;
}

Square &Square::operator+=(const Square &sqr) {
    size += sqr.size;
    return *this;
}

void doSomething(Square sqr) {
    cout << "doSomething called with " << sqr.getSize() << endl;
}

void testSomething() {
    doSomething(23);
}

template<class ItemType>
ItemType smallest(ItemType arr[], ItemType n) {
    ItemType result = arr[0];
    for (int i = 0; i < n; i++)
        if (arr[i] < result)
            result = arr[i];
    return result;
}

class ThreeNode {
private:
    int low, hi;
    ThreeNode *smallPtr;
    ThreeNode *middlePtr;
    ThreeNode *largePtr;
public:
    ThreeNode(int low, int hi) : low{low}, hi{hi} {};
    ~ThreeNode() {
        delete smallPtr;
        delete middlePtr;
        delete largePtr;
    }
};

class Node {
public:
    explicit Node(int data);
    int getItem() const;
    void setItem(int data);
    Node* getNext() const;
    void setNext(Node* next);
private:
    int data;
    Node* next;
};

class List {
public:
    // constructor
    List();
    // destructor
    ~List();
    /*
    // adds the given value, returns true if successful
    bool add(int data) {
        Node *n = new Node(data);
        if (headPtr == nullptr)
            headPtr = n;
        else {
            n->setNext(headPtr);
            headPtr = n;
        }
        return true;
    }
    // removes the given value, returns true if successful
    bool remove(int data) {
        while (headPtr != nullptr) {
            Node *nodeToRemove = headPtr;
            headPtr = headPtr->getNext();
            cout << "Removing: " << (*nodeToRemove) << endl;
            delete nodeToRemove;
        }
        return true;
    }
    */
    bool add(int data) {
        Node * newNode = new Node(data);
        newNode->next = headPtr;
        headPtr = newNode;
    }

    bool add(int data) {
        Node * newNode = new Node(data);
        newNode->next = headPtr;
        if (headPtr == nullptr)
            headPtr->prev = newNode;
        headPtr = newNode;
        return true;
    }

    bool remove(int data) {
        Node * curr;
        Node * doDeletePtr;
        curr = headPtr;
        if (curr == nullptr)
            return false;
        if (curr->data == data) {
            headPtr = curr->next;
            delete curr;
        }
        while (curr != nullptr) {
            toDelete = curr->next;
            if (toDelete->data == data) {
                curr->next = toDelete->next;
                delete toDelete;
                return true;
            }
            curr = curr->next;
        }
        return false;
    }
private:
    Node* headPtr;
    Node * next;
};

int Acker(int m, int n) {
    if (m == 0)
        return n + 1;
    if (n == 0)
        return Acker(m - 1, 1);
    int result = Acker(m, n - 1);
    return Acker(m - 1, result);
}

// #9
bool isPrime(int n) {

}

int countByPrimes(int m, int n) {
    if (m  == n)
        cout << m << endl;
    if (m > n) {
       cout << " " << endl;
    } else if (isPrime(m)) {
        cout << m << ", " << endl;
    }
    countByPrimes(m + 1, n);
}

int main() {
    // #3
    TestRectangle();
    // #6
    cout << "#6" << endl;
    int arr[4] = {11, 2, 33, 44};
    int maxValue = 0;
    int minValue = 0;
    findMaxMin(arr, 4, maxValue, minValue);
    // #7
    sumUpTo(6);
    // #8
    cout << "#8" << endl;
    gcdDijkstra(70, 52);
    // #9

    // #12
    //testSomething();
    int i{10};
    int *iPtr = &i;
    //int *iPtr = *i;
    //int *iPtr = i;
    //iPtr = 20;
    *iPtr = 20;
    //&iPtr = 20;
    assert(*iPtr == i);
    //assert(&iPtr == i);
    Square small(10);
    //Square smPtr = new Square(10);
    Square *smPtr = new Square(10);
    Square *tmpPtr = &small;
    //Square *tmpPtr = small;
    //cout << smPtr.getSize();
    cout << smPtr->getSize() << endl;
    cout << (*smPtr).getSize() << endl;
    //cout << (*smPtr)->getSize();
    delete tmpPtr;
    //delete *tmpPtr;
    delete smPtr;
    //delete *smPtr;
    //delete small;
    //delete *small;
    return 0;
}