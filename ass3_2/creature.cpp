//
// Created by SooYeon Kim on 4/18/2018.
//

#include "creature.h"

// prints current location of creature
ostream &operator<<(ostream &out, const Creature &creature) {
    out << "C(" << creature.row << ", " << creature.column << ")";
    return out;
}

// initialize private variables
Creature::Creature(int row, int column) : row{row}, column{column} {}

// nothing to do
Creature::~Creature() {}

// returns a string in the form of NNEEN
// (where N means North, E means East, etc)
// that will let the creature get to the exit
// if creature cannot get to the exit, return "X"
string Creature::Solve(Maze &maze) {
    maze.MarkAsPath(row, column);
    string path = "";
    if (maze.IsExit(row, column))
        return "";
    else {
        if (goNorth(maze, path) != "X")
            return path;
        else if (goEast(maze, path) != "X")
            return path;
        else if (goWest(maze, path) != "X")
            return path;
        else if (goSouth(maze, path) != "X")
            return path;
        else return "X";
    }
}

// pass the path-so-far by reference to a function
// return a path from this
string Creature::goNorth(Maze &maze, string &path) {
    if (maze.IsClear(row - 1, column) && !maze.IsVisited(row - 1, column)
        && !maze.IsWall(row - 1, column)) {
        row -= 1;
        maze.MarkAsPath(row, column);
        if (maze.IsExit(row, column)) {
            maze.MarkAsPath(row, column);
            return path = "N" + path;
        } else {
            if (goNorth(maze, path) == "X") {
                if (goEast(maze, path) == "X") {
                    if (goWest(maze, path) == "X") {
                        if (goSouth(maze, path) == "X") {
                            maze.MarkAsVisited(row, column);
                            row += 1;
                            return "X";
                        }
                    }
                }
            }
        }
    } else return "X";
    return path = "N" + path;
}

string Creature::goEast(Maze &maze, string &path) {
    if (maze.IsClear(row, column + 1) && !maze.IsVisited(row, column + 1)
        && !maze.IsWall(row, column + 1)) {
        column += 1;
        maze.MarkAsPath(row, column);
        if (maze.IsExit(row, column)) {
            maze.MarkAsPath(row, column);
            return path = "E" + path;
        } else {
            if (goNorth(maze, path) == "X") {
                if (goEast(maze, path) == "X") {
                    if (goWest(maze, path) == "X") {
                        if (goSouth(maze, path) == "X") {
                            maze.MarkAsVisited(row, column);
                            column -= 1;
                            return "X";
                        }
                    }
                }
            }
        }
    } else return "X";
    return path = "E" + path;
}

string Creature::goWest(Maze &maze, string &path) {
    if (maze.IsClear(row, column - 1) && !maze.IsVisited(row, column - 1)
        && !maze.IsWall(row, column - 1)) {
        column -= 1;
        maze.MarkAsPath(row, column);
        if (maze.IsExit(row, column)) {
            maze.MarkAsPath(row, column);
            return path = "W" + path;
        } else {
            if (goNorth(maze, path) == "X") {
                if (goEast(maze, path) == "X") {
                    if (goWest(maze, path) == "X") {
                        if (goSouth(maze, path) == "X") {
                            maze.MarkAsVisited(row, column);
                            column += 1;
                            return "X";
                        }
                    }
                }
            }
        }
    } else return "X";
    return path = "W" + path;
}

string Creature::goSouth(Maze &maze, string &path) {
    if (maze.IsClear(row + 1, column) && !maze.IsVisited(row + 1, column)
        && !maze.IsWall(row + 1, column)) {
        row += 1;
        maze.MarkAsPath(row, column);
        if (maze.IsExit(row, column)) {
            maze.MarkAsPath(row, column);
            return path = "S" + path;
        } else {
            if (goNorth(maze, path) == "X") {
                if (goEast(maze, path) == "X") {
                    if (goWest(maze, path) == "X") {
                        if (goSouth(maze, path) == "X") {
                            maze.MarkAsVisited(row, column);
                            row -= 1;
                            return "X";
                        }
                    }
                }
            }
        }
    } else return "X";
    return path = "S" + path;
}
