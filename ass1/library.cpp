//
// Created by SooYeon Kim on 2018-03-28.
//

#include "library.h"
#include <iostream>
#include <cstring>
using namespace std;

// friend function
ostream &operator<< (ostream &out, const Library &lib) {
    out << lib.arr;
    return out;
}

Library::Library(string name) {
    cout << name << endl;
}

Library::~Library() {
    // nothing to do
}

int Library::findBook(const string &name) const {
    for (int i {0}; i < numberOfBooks; i++) {
        if(arr[i] == name)
            return i;
    }
    return -1;
}
/*
// Check whether they are same string or not
// https://stackoverflow.com/questions/11635/case-insensitive-string-comparison-in-c
bool Library::isEqual(const string &a, const string &b) const {
    unsigned int strLength = a.size();
    if (b.size() != strLength)
        return false;
    for (unsigned int i {0}; i < strLength; ++i) {
        if (tolower(a[i]) != tolower(b[i]))
            return false;
    }
    return true;
}
*/
bool Library::AddBook(const string &name) {
    if (findBook(name) == -1) {
        arr[numberOfBooks++] = name;
        return true;
    }
    else
        return false;
}

bool Library::RemoveBook(const string &name) {
    int index = findBook(name);
    if (index == -1) {
        return false;
    }
    else {
        arr[index] = arr[numberOfBooks - 1];
        numberOfBooks--;
        return true;
    }
}

void Library::ListAllBooks() const {
    for (int i {0}; i < numberOfBooks; i++)
        cout << arr[i] << endl;
}

// Doesn't matter whether it is capital letter or lower letter
bool Library::IsInLibrary(const string &name) const {
    if (findBook(name) == -1) {
        return false;
    }
    else {
        return true;
    }
}