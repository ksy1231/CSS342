//
// Created by SooYeon Kim on 2018-03-28.
//

#ifndef ASS1_LIBRARY_H
#define ASS1_LIBRARY_H

#include <iostream>
#include <cstring>
using namespace std;

class Library {
    friend ostream &operator<< (ostream &out, const Library &lib);
private:
    // the maximum number of books in the library
    static const int MAX = 100;
    string arr[MAX];
    int numberOfBooks = 0;
    int findBook(const string& name) const;
    //bool isEqual(const string &a, const string &b) const;
public:
    // constructor
    Library(string name);

    // destructor
    ~Library();

    // Add a new book,
    // return true for success, false if book already in library
    bool AddBook (const string &name);

    // Remove a book,
    // return true for success, false if book not in library
    bool RemoveBook (const string & name);

    // List all books in library
    void ListAllBooks () const;

    // Return true if book in library, false otherwise
    bool IsInLibrary (const string &name) const;
};
#endif //ASS1_LIBRARY_H
