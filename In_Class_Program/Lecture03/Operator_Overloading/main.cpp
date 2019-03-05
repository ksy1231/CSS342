#include <iostream>
#include "complex.h"
using namespace std;

void test1() {
    Complex c1(10, 20);
    cout << c1 << endl;
    Complex c2(5, -4);
    cout << c2 << endl;
    Complex c3 = c1 + c2;
    cout << c3 << endl;
    Complex c4 = c1 * c2;
    cout << c4 << endl;
    c2 += c1;
    cout << c2 << endl;
}

int main() {
    test1();
    std::cout << "Done!" << std::endl;
    return 0;
}