#include <iostream>

int findMax(vector<int> a)
int findMax(vector<int> &a)
int findMax(const vector<int> &a)
{
    int max = a[0];
    int i;
    for (i = 1; i < a.size(); i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}