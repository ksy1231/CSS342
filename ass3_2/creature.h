//
// Created by SooYeon Kim on 4/18/2018.
//

#ifndef ASS3_CREATURE_H
#define ASS3_CREATURE_H
#include <iostream>
#include "maze.h"
using namespace std;

class Creature {
    // prints current location of creature, for example C(7, 3)
    friend ostream &operator<<(ostream &out, const Creature &creature);

public:
    // constructor
    explicit Creature(int row = 0, int column = 0);
    // destructor
    virtual ~Creature();
    // returns a string in the form of NNEEN
    // (where N means North, E means East, etc)
    // that will let the creature get to the exit
    // if creature cannot get to the exit, return "X"
    string Solve(Maze &maze);
    // pass the path-so-far by reference to a function
    // return a path from this
    string goNorth(Maze &maze, string &path);
    string goEast(Maze &maze, string &path);
    string goWest(Maze &maze, string &path);
    string goSouth(Maze &maze, string &path);
private:
    int row, column;
};

#endif //ASS3_CREATURE_H
