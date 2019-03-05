#include <iostream>
#include <vector>
using namespace std;

void testVector() {
    vector<int> vi;
    vi.push_back(10);
    vi.push_back(30);
    cout << "Using a loop: ";
    for (int i{0}; i < vi.size(); ++i)
        cout << vi[i] << ", ";
    cout << endl;
    cout << "Using range-based for: ";
    for (int i : vi)
        cout << i << ", ";
    cout << endl;
}

int main() {
    testVector();
    std::cout << "Done!" << std::endl;
    return 0;
}