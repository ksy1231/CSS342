//
// Created by SooYeon Kim on 4/18/2018.
//

#include "maze.h"
#include <fstream>
ostream &operator<<(ostream &out, const Maze &maze) {
    for (int row{0}; row < maze.heightOfMaze; row++) {
        for (int column{0}; column < maze.widthOfMaze; column++) {
            out << maze.mazeArr[row][column];
        }
        out << endl;
    }
    return out;
}

// read text file
Maze::Maze(string mazeFile) {
    ifstream myFile;
    myFile.open(mazeFile);
    if (myFile.is_open()) {
        myFile >> widthOfMaze;
        myFile >> heightOfMaze;
        myFile >> rowExit;
        myFile >> columnExit;
        getline(myFile, line);
        for (int row {0}; row < heightOfMaze; row++) {
            for (int column {0}; column < widthOfMaze; column++) {
                myFile.get(mazeArr[row][column]);
            }
            getline(myFile, line);
        }
        myFile.close();
    } else {
        cout << "File could not be opened." << endl;
        exit(1);
    }
}

// nothing to do
Maze::~Maze() {}

// if it is empty space, return true
// otherwise false
bool Maze::IsClear(int row, int column) const {
    return mazeArr[row][column] == ' ';
}

// if it is wall, return true
// otherwise false
bool Maze::IsWall(int row, int column) const {
    return mazeArr[row][column] == 'x';
}

// if it is path, return true
// otherwise false
bool Maze::IsPath(int row, int column) const {
    return mazeArr[row][column] == '*';
}

// if it visited, return true
// otherwise false
bool Maze::IsVisited(int row, int column) const {
    return mazeArr[row][column] == '+';
}

// it it is at exit, return true
// otherwise false
bool Maze::IsExit(int row, int column) const {
    return rowExit == row && columnExit == column;
}

// mark the creature's movement with '*'
void Maze::MarkAsPath(int row, int column) {
    mazeArr[row][column] = '*';
}

// mark the creature's visited spaces with '+'
void Maze::MarkAsVisited(int row, int column) {
    mazeArr[row][column] = '+';
}
