#include <iostream>
using namespace std;

struct Rectangle {
    int length;
    int width;
};

//int Area(Rectangle rect) // value rect is copied
int Area(Rectangle &rect) // reference, we can change the value
//int Area(const Rectangle &rect) // const reference, cannot change it
{
    int temp;
    temp = rect.length;
    rect.length = 35;
    return (rect.length * rect.width);
}

void TestRectangle() {
    int result;
    Rectangle r = {3, 3};
    result = Area(r);
    cout << "length = " << r.length << endl;
    cout << "width = " << r.width << endl;
    cout << "Area = " << result << endl;
}

int main() {
    TestRectangle();
    return 0;
}