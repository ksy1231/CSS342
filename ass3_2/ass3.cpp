#include "maze.h"
#include "creature.h"

void testMaze1() {
    Maze m1("maze1.txt");
    Creature c1(4, 0);
    string path = c1.Solve(m1);
    std::cout << "m1's path: " << path << std::endl;
    std::cout << m1 << std::endl;
}

void testMaze2() {
    Maze m2("maze2.txt");
    Creature c2(4, 3);
    string path = c2.Solve(m2);
    std::cout << "m2's path: " << path << std::endl;
    std::cout << m2 << std::endl;
}

int main() {
    testMaze1();
    testMaze2();
    std::cout << "Done" << std::endl;
    return 0;
}
