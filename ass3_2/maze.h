//
// Created by SooYeon Kim on 4/18/2018.
//

#ifndef ASS3_MAZE_H
#define ASS3_MAZE_H

#define MAX_SIZE 100

#include <iostream>
#include <fstream>
using namespace std;

class Maze {
    // follows the format provided above printing the maze
    friend ostream &operator<<(ostream &out, const Maze &maze);

public:
    // Maze constructor requiring a valid file name
    explicit Maze(string mazeFile = "");
    // destructor
    virtual ~Maze();

    // show the square is clear
    bool IsClear(int row, int column) const;
    // show the square is blocked and represents part of the wall
    bool IsWall(int row, int column) const;
    // show the square lies on the path to the exit
    bool IsPath(int row, int column) const;
    // show the square was visited, but going that way led to an impasse
    bool IsVisited(int row, int column) const;
    // show the square is at exit
    bool IsExit(int row, int column) const;

    // mark the maze with *
    void MarkAsPath(int row, int column);
    // mark the maze with +
    void MarkAsVisited(int row, int column);
private:
    int widthOfMaze, heightOfMaze;
    int rowExit, columnExit;
    char mazeArr[MAX_SIZE][MAX_SIZE];
    string line;
};

#endif //ASS3_MAZE_H
