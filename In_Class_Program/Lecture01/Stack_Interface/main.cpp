#include <iostream>

class IntStack {
public:
    bool Pop();
    int Top();
    bool Push(int number);
    int Size();
    int Peek();
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}