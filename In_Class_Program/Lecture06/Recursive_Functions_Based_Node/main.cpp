#include <iostream>
#include "node.h"
#include "list.h"

// 1, 1, 2, 3, 5, 8, 13
// fib(0) = 0
// fib(1) = 1
// fib(2) = 1
// fib(n) = fib(n-1) + fib(n-2);
int fib(int n) {
    if (n == 0)
        return 0;
    if(n <= 2)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}

int maxArray(int someArray[], int start, int end) {
    if (start == end)
        return someArray[start];
    else {
        int mid = (start + end) / 2;
        return max(maxArray(someArray, start, mid), maxArray(someArray, mid + 1, end));
    }
}

void writeBackwards(string s) {
    if (s.length() > 0) {
        // recursive case
        cout << s[s.length() - 1];
        writeBackwards(s.substr(0, s.length() - 1));
    }
}

void writeBackwards2(string s, int first, int last) {
    if (first <= last) {
        // recursive case
        cout << s[last];
        writeBackwards2(s, first, last - 1);
    }
}

int factorial(int n) {
    if (n < 1)
        return 1;
    else
        return n * factorial(n - 1);
}

void test1() {
    Node<int> n1(20);
    cout << n1 << endl;
    Node<int> n2(20);
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

void test3() {
    cout << factorial(5) << endl;
    cout << factorial(0) << endl;
    cout << factorial(1) << endl;
    writeBackwards("cat");
    cout << endl;
    writeBackwards("hello world");
    cout << endl;
    writeBackwards2("cat", 0, 2);
    cout << endl;
}

void test4() {
    int anArray[]{1, 4, 203, 2, 49, 6, 7555};
    cout << maxArray(anArray, 0, 6) << endl;
    cout << fib(1) << ", " << fib(2)
         << ", " << fib(3)
         << ", " << fib(4)
         << ", " << fib(5)
         << ", " << fib(6) << endl;
}

int main() {
    test1();
    test2();
    test3();
    test4();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}