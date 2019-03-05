#include <iostream>
using namespace std;

// by value
void swapByValue(string a, string b) {
    string tmp = a;
    a = b;
    b = tmp;
}

// by reference
void swapByReference(string &a, string &b) {
    string tmp = a;
    a = b;
    b = tmp;
}

// by const reference
void swapByConstReference(const string &a, const string &b) {
    string tmp = a;
    a = b;
    b = tmp;
}

int main() {
    return 0;
}