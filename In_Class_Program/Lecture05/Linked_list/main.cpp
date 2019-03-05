#include <iostream>
#include "node.h"
#include "list.h"

void test1() {
    Node n1;
    cout << n1 << endl;
    Node n2(20);
    cout << n2 << endl;
}

void test2() {
    List someList;
    someList.add(4);
    someList.add(25);
    cout << someList << endl;
    someList.add(7);
    cout << someList << endl;
}

int main() {
    //test1();
    test2();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}