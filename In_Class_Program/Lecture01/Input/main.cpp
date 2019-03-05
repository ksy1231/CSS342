#include <iostream>
using namespace std;

void TestIO() {
    int number;
    string str;
    cout << "Enter a number: ";
    cin >> number;
    cout << "Enter a string: ";
    cin >> str;
    cout << "Number: " << number << ", string: " << str << endl;
    // full line
    cin.ignore(); // ignores \n that cin >> str has lefted (if user pressed enter key)
    cout << "Enter your full name: ";
    getline(cin, str);
    cout << "Hello, " << str << endl;
}

int main() {
    TestIO();
    return 0;
}