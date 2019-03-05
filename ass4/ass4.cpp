#include <iostream>
#include "skiplist.h"

using namespace std;

void test04() {
    SkipList s(5);
    for (int i = 0; i< 20; ++i) {
        int number = rand() % 100;
        s.Add(number);
        cout << "After adding " << number << endl;
        cout << s << endl;
    }
}

int main() {
    test04();
    std::cout << "Done!" << std::endl;
    return 0;
}
