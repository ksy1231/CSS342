#include <iostream>
using namespace std;

void LargestOfTwo() {
    int firstNumber;
    int secondNumber;
    cout << "Enter two numbers: ";
    cin >> firstNumber;
    cin >> secondNumber;
    // int largest = (firstNumber > secondNumber ? firstNumber : secondNumber);
    int largest;
    if (firstNumber > secondNumber) {
        largest = firstNumber;
    } else {
        largest = secondNumber;
    }
    cout << "Largest is: " << largest << endl;
}


// prints largest after each input
void LargestAllTheTime() {
    int number;
    int largest = INT32_MIN;
    // print user prompt
    cout << "Keep entering numbers";
    while (cin >> number) {
        if (number > largest)
            largest = number;
        cout << "Largest is: " << largest << endl;
    }
}

int main() {
    LargestOfTwo();
    LargestAllTheTime();
    cout << "Done!" << endl;
    return 0;
}