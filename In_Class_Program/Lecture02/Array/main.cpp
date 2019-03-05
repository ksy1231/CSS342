#include <iostream>
using namespace std;

void TestArray() {
    int nums[10];
    nums[0] = 23;
    for (int i{0}; i < 10; ++i) {
        cout << nums[i] << ", ";
    }
    cout << endl;
    string str[10];
    str[0] = "Hello";
    for(int i{0}; i < 10; ++i) {
        cout << str[i] << ", ";
    }
    cout << endl;
}

int main() {
    TestArray();
    std::cout << "Done!" << std::endl;
    return 0;
}