#include <iostream>
#include <cassert>
using namespace std;

void TestString() {
    string strHello = "Hello";
    string strWorld = "World";
    string strFull = strHello + " " + strWorld;
    cout << strFull << endl;
    assert(strFull == "Hello World");
    assert(strFull[0] == 'H');
    assert(strFull[strFull.length() - 1] == 'd');
}

void TestArray() {
    int nums[10];
    nums[0] = 23;
    for (int i{0}; i < 10; ++i) {
        cout << nums[i] << ", ";
    }
    cout << endl;
    string str[10];
    str[0] = "Hello";
    for (int i{0}; i < 10; ++i) {
        cout << str[i] << ", ";
    }
    cout << endl;
}

int main() {
    //TestString();
    TestArray();
    return 0;
}